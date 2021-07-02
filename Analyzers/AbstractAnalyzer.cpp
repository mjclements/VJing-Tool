#include "AbstractAnalyzer.hpp"
#include "AudioStream.hpp"
#include "Connector.hpp"

AbstractAnalyzer::AbstractAnalyzer(){ };




AbstractAnalyzer::AbstractAnalyzer(AudioStream as)
{
    audioStream = & as;

}

void	AbstractAnalyzer::registerConnector(Connector toInform)
{
	observers.push_back(&toInform);
}

int64_t	AbstractAnalyzer::getValue()
{
	return value;
}


AbstractAnalyzer::~AbstractAnalyzer(){
}


