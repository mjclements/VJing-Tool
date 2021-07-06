#include "Connector.hpp"
class ThresholdConnector : public Connector {
    public:
        ThresholdConnector(int16_t thresh, int16_t off = 0);
        void setValue(int16_t);
    protected:
        int16_t threshold;
        int16_t off;

};