#pragma once

#include <vector>
#include <stdint.h>


using namespace std;
class AudioStream;
class Connector;
class AbstractAnalyzer {

public:
    AbstractAnalyzer(); //Default Constructor
    AbstractAnalyzer(AudioStream *as); 
    AbstractAnalyzer(const AbstractAnalyzer &a); // Copy Constructor
    void registerConnector(Connector* toInform);
    int16_t getValue();
    virtual void setValue(std::vector<int16_t> *PCMCodes) = 0; //This will be where each Analyzer does its magic.
    ~AbstractAnalyzer(); // Destructor
protected:
    int16_t value;
    vector<Connector *> observers;
    AudioStream *audioStream;

};

