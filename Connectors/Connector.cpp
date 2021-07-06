
#include "Connector.hpp"
#include <iostream>
int16_t	 Connector::getValue()
{
     //std::cout << int( min + ((max - min ) * ((float) value / (float) 0xefff)) ) << std::endl;
    return int( min + ((max - min ) * ((float) value / (float) 0xefff)) );

}

void Connector::registerVisual(Visual *v)
{
	visuals.push_back(v);
}


Connector::Connector(){
    max = 0xefff;
    min = 0;
    value = 0;
}

Connector::~Connector(){
    
}

void Connector::setMax(uint16_t max){
    this->max = max;
}
void Connector::setMin(uint16_t min){
    this->min   = min;
}