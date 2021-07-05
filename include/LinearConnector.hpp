#pragma once
#include "Connector.hpp"
class LinearConnector : public Connector {
    public:
        LinearConnector();
        void setValue(int64_t AnalysisValue);
        int32_t getValue();

};