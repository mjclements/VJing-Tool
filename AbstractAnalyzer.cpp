#include "AbstractAnalyzer.hpp"

class AbstractAnalyzer {

private:
    vector<Connector *> observers{};
    AudioStream audioStream;

AbstractAnalyzer::AbstractAnalyzer(){ };




AbstractAnalyzer::AbstractAnalyzer(AudioStream as)
{
    observers =  { };
    audioStream = as;

}

void	AbstractAnalyzer::registerConnector(Connector toInform)
{
	observers.push_back(&toInform);
}

double	AbstractAnalyzer::getValue()
{
	
}

void	AbstractAnalyzer::setValue()
{
	
}

void    AbstractAnalyzer::~AbstractAnalyzer(){
    delete &observers;
}

};
