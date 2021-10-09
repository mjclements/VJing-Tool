#include "BassAnalyzer.hpp"
#include <cmath>
#include <iostream>

void BassAnalyzer::setValue(std::vector<int16_t> *PCMCodes)
{
   // std::cout << PCMCodes.size() << std::endl;
   float temp = 0;
    value = 0;
    for(int16_t PCMCode : *PCMCodes){
            temp += std::abs(PCMCode);
    }
    
    value = (int16_t)(temp / (PCMCodes->size()+1));
   // cout << value << endl;

    for(Connector *c : observers){
        c->setValue(value);
    }
	
}


BassAnalyzer::BassAnalyzer()
{
	
}

BassAnalyzer::BassAnalyzer(AudioStream * as) : AbstractAnalyzer::AbstractAnalyzer( as)
{
    
}