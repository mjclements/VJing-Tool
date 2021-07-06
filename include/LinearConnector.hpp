#pragma once
#include "Connector.hpp"
class LinearConnector : public Connector {
    public:
        LinearConnector();
        void setValue(int16_t AnalysisValue);
        int16_t getValue();

};