#pragma once
#include "AbstractAnalyzer.hpp"
#include "Connector.hpp"

class VolumeAnalyzer : public AbstractAnalyzer {
    public:
        void setValue(std::vector<int16_t> *PCMCodes);

        
};