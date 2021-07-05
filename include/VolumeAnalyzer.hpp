#pragma once
#include "AbstractAnalyzer.hpp"
#include "Connector.hpp"
class VolumeAnalyzer : public AbstractAnalyzer {
    public:
        VolumeAnalyzer();
        void setValue(std::vector<int16_t> *PCMCodes);
        VolumeAnalyzer(AudioStream *as);
        ~VolumeAnalyzer();

        
};