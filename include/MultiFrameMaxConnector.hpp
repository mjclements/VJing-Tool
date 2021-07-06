#pragma once
#include "Connector.hpp"

class MultiFrameMaxConnector : public Connector {
    public:
        MultiFrameMaxConnector(int16_t n);
        void setValue(int16_t AnalysisValue);
        int16_t getValue();
    protected:
        std::vector<int> frames;
        int current;
        int maxFrames;

};