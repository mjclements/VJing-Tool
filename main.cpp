#include "AudioStream.hpp"
#include "VolumeAnalyzer.hpp"
#include <iostream>
int main()
{

    AudioStream* audioStream = new AudioStream();
    Sleep(500);
    audioStream->getFrame();
    AbstractAnalyzer *absanal = new VolumeAnalyzer();
    audioStream->registerObserver(absanal);
    while(true){
    audioStream->getFrame();
    std::cout << absanal->getValue() << std::endl;
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