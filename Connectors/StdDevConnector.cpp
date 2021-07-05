#include "StdDevConnector.hpp"
#include <algorithm>
#include <math.h>
void	StdDevConnector::setValue(int64_t AnalysisValue)
{
    frames[current] = AnalysisValue;

    current = (current + 1) % maxFrames;
    auto avg = 0;
    auto sse = 0;
    std::for_each(frames.begin(), frames.end(), [&] (int64_t n) {
        avg += (n / maxFrames);
    });
    std::for_each(frames.begin(), frames.end(), [&] (int64_t n) {
        sse += (n - avg)*( n - avg);
    });

    value = sqrt(sse/(maxFrames-1));

}

StdDevConnector::StdDevConnector(int64_t frameMax){
    current = 0;
    maxFrames = frameMax;
    for( int i = 0; i < frameMax; i++){
        frames.push_back(0);
    }
}

int32_t StdDevConnector::getValue(){
    return value;
}