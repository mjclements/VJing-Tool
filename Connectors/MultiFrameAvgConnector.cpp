#include "MultiFrameAvgConnector.hpp"
#include <algorithm>
void	MultiFrameAvgConnector::setValue(int64_t AnalysisValue)
{
    frames[current] = AnalysisValue;

    current = (current + 1) % maxFrames;
    value = 0;
    std::for_each(frames.begin(), frames.end(), [&] (int64_t n) {
        value += (n / maxFrames);
    });
}

MultiFrameAvgConnector::MultiFrameAvgConnector(int64_t frameMax){
    current = 0;
    maxFrames = frameMax;
    for( int i = 0; i < frameMax; i++){
        frames.push_back(0);
    }
}

int32_t MultiFrameAvgConnector::getValue(){
    return value;
}