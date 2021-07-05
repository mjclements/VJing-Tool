#include "LinearConnector.hpp"

void	LinearConnector::setValue(int64_t AnalysisValue)
{
    value = AnalysisValue;
}

LinearConnector::LinearConnector(){
    value = 255;
}

int32_t LinearConnector::getValue(){
            return value;
}