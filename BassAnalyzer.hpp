#pragma once
#include "AbstractAnalyzer.hpp"
#include "Connector.hpp"

class BassAnalyzer : AbstractAnalyzer {
public:
    BassAnalyzer();
    BassAnalyzer(AudioStream *as);
    BassAnalyzer(const BassAnalyzer &a);
    void registerConnector(Connector toInform);
    void setValue(std::vector<int16_t> *PCMCodes);
    double getValue();
    void process(unsigned int *PCMCodes);
private:

};