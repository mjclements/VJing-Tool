#include "MultiFrameMaxConnector.hpp"
#include <algorithm>
void	MultiFrameMaxConnector::setValue(int16_t AnalysisValue)
{
    frames[current] = AnalysisValue;

    current = (current + 1) % maxFrames;
    value = 0;
    std::for_each(frames.begin(), frames.end(), [&] (int64_t n) {
        n > value ? value = n : n;
    });
}

MultiFrameMaxConnector::MultiFrameMaxConnector(int16_t frameMax){
    current = 0;
    maxFrames = frameMax;
    for( int i = 0; i < frameMax; i++){
        frames.push_back(0);
    }
}

int16_t MultiFrameMaxConnector::getValue(){
    return value;
}