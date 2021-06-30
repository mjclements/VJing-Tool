#pragma once

#include <vector>

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
    void setValue(unsigned int *PCMCodes); //This will be where each Analyzer does its magic.
    ~AbstractAnalyzer(); // Destructor
private:
    double value;
    vector<Connector *> observers;
    AudioStream *audioStream;

};

