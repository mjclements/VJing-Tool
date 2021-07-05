#pragma once
#include "Connector.hpp"

class StdDevConnector : public Connector {
    public:
        StdDevConnector(int64_t n);
        void setValue(int64_t AnalysisValue);
        int32_t getValue();
    protected:
        std::vector<int> frames;
        int current;
        int maxFrames;

};