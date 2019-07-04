#include "doublefilter.h"

DoubleFilter::DoubleFilter(int sizeX1, int sizeY1, int sizeX2, int sizeY2, int bufferSize, std::string tag){
    _bufferSize = bufferSize;
    _middleSignal = new float[bufferSize];
    filter1_ = new SimpleFilter(sizeX1, sizeY1, bufferSize);
    filter2_ = new SimpleFilter(sizeX2, sizeY2, bufferSize);
    _tag = tag;
    _writing = false;
}

void DoubleFilter::filter(float *x, float *y){
    filter1_->filter(x, _middleSignal);
    filter2_->filter(_middleSignal, y);
    if (_writing) utils::writeFileLines("../Data/out" + _tag + ".txt", y, _bufferSize);

}

void DoubleFilter::setCoefficient(const float *coeffX0, const float *coeffY0, const float *coeffX1, const float *coeffY1, const float gain1, const float gain2){
    filter1_->setCoefficients(coeffX0, coeffY0, gain1);
    filter2_->setCoefficients(coeffX1, coeffY1, gain2);
}

void DoubleFilter::setWriting(bool writing){
    _writing = writing;
}