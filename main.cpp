#include <windows.h>
#include <mmdeviceapi.h>
#include <audioclient.h>

#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h> // for sin()
#include <stdint.h>

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
    void* audioClient;
    hr = pp->Activate(IID_IAudioClient,CLSCTX_ALL,NULL,&audioClient);
    assert(hr==S_OK);
    (IAudioClient *)audioClient;
    // audioClient->initalize(AUDCLNT_SHAREMODE_SHARED, )
    // printf(audioClient.)
    return 0;
}