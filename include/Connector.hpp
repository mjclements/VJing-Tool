#pragma once
#include <stdint.h>
#include <vector>
class Visual;

class Connector {
    public:
        int32_t getValue();
        void registerVisual(Visual *v);
        virtual void setValue(int64_t AnalysisValue) {};
        Connector();
        ~Connector();
        void setMax(uint32_t max);
        void setMin(uint32_t min);
    protected:
        int64_t value;
        std::vector<Visual *> visuals;
        uint32_t max;
        uint32_t min;
};

