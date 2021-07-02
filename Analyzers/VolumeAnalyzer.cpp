#include "VolumeAnalyzer.hpp"
#include <cmath>
#include <iostream>
void VolumeAnalyzer::setValue(std::vector<int16_t> *PCMCodes)
{
   // std::cout << PCMCodes.size() << std::endl;
    value = 0;
    for(int16_t PCMCode : *PCMCodes){
            value += std::abs(PCMCode);
    }
    //cout << PCMCodes->size() << endl;
    value = (value / (PCMCodes->size()+1));

    for(Connector *c : observers){
        c->setValue(value);
    }

}