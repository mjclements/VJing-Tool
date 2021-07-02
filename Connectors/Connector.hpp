#pragma once
#include "Visual.hpp"
#include <stdint.h>
#include <vector>
class Visual;

class Connector {
    public:
        int32_t getValue();
        void registerVisual(Visual *v);
        virtual void setValue(int64_t AnalysisValue) {};
    protected:
        int64_t value;
        std::vector<Visual *> visuals;


};

