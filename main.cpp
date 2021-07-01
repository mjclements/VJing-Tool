#include "AudioStream.hpp"
int main()
{

    AudioStream* audioStream = new AudioStream();
    Sleep(500);
    audioStream->getFrame();
    // UINT32* numBuffFrames;
    // hr = audioClient->GetCurrentPadding(numBuffFrames);
    // std::cout << *numBuffFrames;
    // assert(hr==S_OK);
    
    // hr = audioClient->Stop();
    // std::cout << std::hex << hr;
    // assert(hr == S_OK);
    return 0;
}