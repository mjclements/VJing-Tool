#pragma once
#include "Connector.hpp"

class MultiFrameMaxConnector : public Connector {
    public:
        MultiFrameMaxConnector(int64_t n);
        void setValue(int64_t AnalysisValue);
        int32_t getValue();
    protected:
        std::vector<int> frames;
        int current;
        int maxFrames;

};