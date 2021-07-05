
#include "Connector.hpp"

int32_t	 Connector::getValue()
{
    return value;
}

void Connector::registerVisual(Visual *v)
{
	visuals.push_back(v);
}


Connector::Connector(){

}

Connector::~Connector(){
    
}