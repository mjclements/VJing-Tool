#pragma once

#include <vector>
#include <stdint.h>


using namespace std;
class AudioStream;
class Connector;
class AbstractAnalyzer {

public:
    AbstractAnalyzer(); //Default Constructor
    AbstractAnalyzer(AudioStream as); 
    AbstractAnalyzer(const AbstractAnalyzer &a); // Copy Constructor
    void registerConnector(Connector toInform);
    int64_t getValue();
    virtual void setValue(std::vector<int16_t> *PCMCodes) {}; //This will be where each Analyzer does its magic.
    ~AbstractAnalyzer(); // Destructor
protected:
    int64_t value;
    vector<Connector *> observers;
    AudioStream *audioStream;

};

