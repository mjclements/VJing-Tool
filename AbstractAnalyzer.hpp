#pragma once
#include "AudioStream.hpp"
#include "Connector.hpp"

class AbstractAnalyzer {

public:
    AbstractAnalyzer(AudioStream as);
    void registerConnector(Connector toInform);
    double getValue();
    void setValue();
private:
    double value;
    AudioStream audioStream;
};

