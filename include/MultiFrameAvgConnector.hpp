#pragma once
#include "Connector.hpp"

class MultiFrameAvgConnector : public Connector {
    public:
        MultiFrameAvgConnector(int64_t n);
        void setValue(int64_t AnalysisValue);
        int32_t getValue();
    protected:
        std::vector<int> frames;
        int current;
        int maxFrames;

};