#include "StdDevConnector.hpp"
#include <algorithm>
#include <math.h>
#include <iostream>
void	StdDevConnector::setValue(int16_t AnalysisValue)
{
    frames[current] = AnalysisValue;

    current = (current + 1) % maxFrames;
    auto avg = 0;
    auto sse = 0;
    std::for_each(frames.begin(), frames.end(), [&] (int16_t n) {
        avg += (n / maxFrames);
    });
    std::for_each(frames.begin(), frames.end(), [&] (int16_t n) {
        sse += (n - avg)*( n - avg);
    });

    value = sqrt(sse/(maxFrames-1));
    //std::cout << "value " << value << std::endl;

}

StdDevConnector::StdDevConnector(int16_t frameMax){
    current = 0;
    maxFrames = frameMax;
    for( int i = 0; i < frameMax; i++){
        frames.push_back(0);
    }
}

int16_t StdDevConnector::getValue(){
    return value;
}