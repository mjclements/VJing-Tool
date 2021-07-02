#pragma once
#include "AbstractAnalyzer.hpp"

class BassAnalyzer : AbstractAnalyzer {
public:
    BassAnalyzer();
    BassAnalyzer(AudioStream as);
    BassAnalyzer(const BassAnalyzer &a);
    void registerConnector(Connector toInform);
    double getValue();
    void process(unsigned int *PCMCodes);
private:

};