#include <windows.h>
#include <mmdeviceapi.h>
#include <iostream>
#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h> // for sin()
#include <iomanip>
#include <vector>
#include "AudioStream.hpp"
#include "AbstractAnalyzer.hpp"
#define AUTOCONVERTPCM_QUALITY 0x88000000
AudioStream::AudioStream()
{
    analyzers = {};
    leftBuffer = {};
    rightBuffer = {};
    //Beging Windows API connection code
	HRESULT hr = CoInitializeEx(nullptr, COINIT_SPEED_OVER_MEMORY);
    assert(hr==S_OK);
    IMMDeviceEnumerator* deviceEnum;
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (LPVOID*)(&deviceEnum));
    assert(hr==S_OK);
    IMMDevice* pp;
    hr = deviceEnum->GetDefaultAudioEndpoint(eRender,eMultimedia,&pp);
    assert(hr==S_OK);
    hr = pp->Activate(__uuidof(IAudioClient),CLSCTX_ALL,NULL,(LPVOID*)&audioClient);
    assert(hr==S_OK);
    WAVEFORMATEX mixFormat = {};
    mixFormat.wFormatTag = WAVE_FORMAT_PCM;
    mixFormat.nChannels = 2;
    mixFormat.nSamplesPerSec = 44100;//defaultMixFormat->nSamplesPerSec;
    mixFormat.wBitsPerSample = 16;
    mixFormat.nBlockAlign = (mixFormat.nChannels * mixFormat.wBitsPerSample) / 8;
    mixFormat.nAvgBytesPerSec = mixFormat.nSamplesPerSec * mixFormat.nBlockAlign;
    const int64_t bufferSize = 1000000;
    REFERENCE_TIME size = bufferSize * 2;
    hr = audioClient->Initialize(AUDCLNT_SHAREMODE_SHARED, AUDCLNT_STREAMFLAGS_LOOPBACK | AUTOCONVERTPCM_QUALITY,size,0,&mixFormat,nullptr);
    assert(hr == S_OK);

    hr = audioClient->GetService(__uuidof(IAudioCaptureClient), (LPVOID*) &captureClient);
    assert( hr == S_OK );
    hr = audioClient->Start();
}
std::vector<int16_t> AudioStream::getFrame(){
    HRESULT hr;
    BYTE* bufferByte; //pointer to the start of the buffer
    UINT32 numberOfAvailableFrames; 
    DWORD flags;
    UINT64 devicePosition;
    UINT64 qpcPosition;
    UINT32 packetLength = 0;
    hr = captureClient->GetNextPacketSize(&packetLength);
    hr = captureClient->GetBuffer(&bufferByte, &numberOfAvailableFrames, &flags, &devicePosition, &qpcPosition );
    
    assert( hr == S_OK || hr == AUDCLNT_S_BUFFER_EMPTY);
    int16_t* codePointer = (int16_t*) bufferByte;
    if(hr == S_OK){  //Don't inform the Analyzers unless you've got new music!
        for(int i = 0; i < packetLength/2; i+=2 ){
            leftBuffer.push_back(codePointer[i]);
            rightBuffer.push_back(codePointer[i+1]);
            centerBuffer.push_back(codePointer[i]/2 + codePointer[i+1]/2); //avg of L and R channels
           //std::cout << std::dec << codePointer[i] << ", ";

        }
        captureClient->ReleaseBuffer(packetLength); //releasing number of frames read from the buffer
        for(AbstractAnalyzer *observer : analyzers)
        {
            observer->setValue(&centerBuffer);
        }
        leftBuffer.clear();
        rightBuffer.clear();
        centerBuffer.clear();
        }
    return leftBuffer;
}



void AudioStream::registerObserver(AbstractAnalyzer *analyzer)
{
    analyzers.push_back(analyzer);
}

