#include "ThresholdConnector.hpp"
ThresholdConnector::ThresholdConnector(int16_t threshold, int16_t off): Connector(){
    this->threshold = threshold;
    this->off = off;
}
void ThresholdConnector::setValue(int16_t analysisValue){
    if(analysisValue > threshold){
        value = analysisValue;
    }
    else{
        value = off;
    }
}