#include "LinearConnector.hpp"

void	LinearConnector::setValue(int16_t AnalysisValue)
{
    value = AnalysisValue;
}

LinearConnector::LinearConnector(){
    value = 255;
}

int16_t LinearConnector::getValue(){
            return value;
}