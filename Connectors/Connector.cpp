
#include "Connector.hpp"

int32_t	 Connector::getValue()
{
    return min + ((max - min ) * (value / 0xffffffff));

}

void Connector::registerVisual(Visual *v)
{
	visuals.push_back(v);
}


Connector::Connector(){
    max = 0xffffffff;
    min = 0;
    value = 0;
}

Connector::~Connector(){
    
}

void Connector::setMax(uint32_t max){
    this->max = max;
}
void Connector::setMin(uint32_t min){
    this->min   = min;
}