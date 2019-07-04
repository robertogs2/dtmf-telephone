#ifndef MEGAFILTER_H
#define MEGAFILTER_H

#include "doublefilter.h"
#include "vectoroperations.h"
#include "constants.h"

class MegaFilter
{
public:
    MegaFilter();
    void init(int buffers, int bufferSize);
    void setEmpiricalVariables(int movingAverageSamples, float digitalThreshold, int mininumHigh);
    void filter(float* x);
    int analyze();

    int _buffers;
    int _bufferSize;

    int _movingAverageSamples; // Samples for average
    float _digitalThreshold; // threshold for energy
    int _mininumHigh; // minimun amount of samples to be one to consider

    float* _filteredSignal;
    float* _tempSignal1;
    float* _tempSignal2;
    DoubleFilter* _filterUnit;

    int _states[3];

};

#endif // MEGAFILTER_H
