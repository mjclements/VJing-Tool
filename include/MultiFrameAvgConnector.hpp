#pragma once
#include "Connector.hpp"

class MultiFrameAvgConnector : public Connector {
    public:
        MultiFrameAvgConnector(int16_t n);
        void setValue(int16_t AnalysisValue);
        int16_t getValue();
    protected:
        std::vector<int> frames;
        int current;
        int maxFrames;

};