#pragma once

#include <list>

#include "AudioStream.hpp"
#include "Connector.hpp"

using namespace std;

class AbstractAnalyzer {

public:
    AbstractAnalyzer(); //Default Constructor
    AbstractAnalyzer(AudioStream as); 
    AbstractAnalyzer(const AbstractAnalyzer &a); // Copy Constructor
    void registerConnector(Connector toInform);
    double getValue();
    void setValue();
private:
    double value;
    list<Connector *> observers{};
    AudioStream *audioStream;

};

