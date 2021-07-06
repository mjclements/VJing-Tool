#pragma once
#include <stdint.h>
#include <vector>
class Visual;

class Connector {
    public:
        int16_t getValue();
        void registerVisual(Visual *v);
        virtual void setValue(int16_t AnalysisValue) {};
        Connector();
        ~Connector();
        void setMax(uint16_t max);
        void setMin(uint16_t min);
    protected:
        int16_t value;
        std::vector<Visual *> visuals;
        uint16_t max;
        uint16_t min;
};

