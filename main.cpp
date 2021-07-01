#include <windows.h>
#include <mmdeviceapi.h>
#include <audioclient.h>
#include <iostream>
#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h> // for sin()
#include <stdint.h>
#define AUTOCONVERTPCM_QUALITY 0x88000000
int main()
{
    HRESULT hr = CoInitializeEx(nullptr, COINIT_SPEED_OVER_MEMORY);
    assert(hr==S_OK);
    IMMDeviceEnumerator* deviceEnum;
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (LPVOID*)(&deviceEnum));
    assert(hr==S_OK);
    IMMDevice* pp;
    hr = deviceEnum->GetDefaultAudioEndpoint(eRender,eMultimedia,&pp);
    assert(hr==S_OK);
    IAudioClient* audioClient;
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
    //std::cout << std::hex << hr;
    assert(hr == S_OK);
    
    IAudioCaptureClient* captureClient;
    hr = audioClient->GetService(__uuidof(IAudioCaptureClient), (LPVOID*) &captureClient);
    assert( hr == S_OK );
    hr = audioClient->Start();
    Sleep(4000);
    BYTE* bufferByte; //pointer to the start of the buffer
    UINT32 numberOfAvailableFrames; 
    DWORD flags;
    UINT64 devicePosition;
    UINT64 qpcPosition;
    UINT32 packetLength = 0;
    hr = captureClient->GetNextPacketSize(&packetLength);
    hr = captureClient->GetBuffer(&bufferByte, &numberOfAvailableFrames, &flags, &devicePosition, &qpcPosition );

    std::cout << std::hex << hr;

    assert( hr == S_OK || hr == AUDCLNT_S_BUFFER_EMPTY);

    if(hr == S_OK){  //Don't inform the Analyzers unless you've got new music!
        std::cout << *bufferByte << std::endl;
    }
    // UINT32* numBuffFrames;
    // hr = audioClient->GetCurrentPadding(numBuffFrames);
    // std::cout << *numBuffFrames;
    // assert(hr==S_OK);



    // hr = audioClient->Stop();
    // std::cout << std::hex << hr;
    // assert(hr == S_OK);
    return 0;
}