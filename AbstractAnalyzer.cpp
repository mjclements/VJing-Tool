#include "AbstractAnalyzer.hpp"


AbstractAnalyzer::AbstractAnalyzer(){ };




AbstractAnalyzer::AbstractAnalyzer(AudioStream as)
{
    audioStream = & as;

}

void	AbstractAnalyzer::registerConnector(Connector toInform)
{
	observers.push_back(&toInform);
}

double	AbstractAnalyzer::getValue()
{
	
}


AbstractAnalyzer::~AbstractAnalyzer(){
    delete &observers;
}

