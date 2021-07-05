#include "VolumeAnalyzer.hpp"
#include <cmath>
#include <iostream>

void	VolumeAnalyzer::setValue(std::vector<int16_t> *PCMCodes)
{
   // std::cout << PCMCodes.size() << std::endl;
    value = 0;
    for(int16_t PCMCode : *PCMCodes){
            value += std::abs(PCMCode);
    }
    
    value = (value / (PCMCodes->size()+1));
    //cout << value << endl;

    for(Connector *c : observers){
        c->setValue(value);
    }
   // cout << observers.size() << endl;
	
}

VolumeAnalyzer::~VolumeAnalyzer()
{
	
}

VolumeAnalyzer::VolumeAnalyzer()
{
	
}

VolumeAnalyzer::VolumeAnalyzer(AudioStream * as) : AbstractAnalyzer::AbstractAnalyzer( as)
{
    
}