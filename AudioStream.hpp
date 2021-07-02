#pragma once
#include <audioclient.h>
#include <stdint.h>
#include <vector>
class AbstractAnalyzer;

class AudioStream {

    public:
        AudioStream();
        std::vector<int16_t> getFrame();
      //  void register(AbstractAnalyzer analyzer);
      void registerObserver(AbstractAnalyzer *analyzer);
      
    private:
        IAudioClient* audioClient;
        IAudioCaptureClient* captureClient;
        std::vector<AbstractAnalyzer *> analyzers;
    protected:
        std::vector<int16_t> leftBuffer;
        std::vector<int16_t> rightBuffer;
        std::vector<int16_t> centerBuffer;

};

