
#include "Connector.hpp"

int32_t	 Connector::getValue()
{
    return 1;
}

void Connector::registerVisual(Visual *v)
{
	visuals.push_back(v);
}

