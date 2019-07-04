#include "simplefilter.h"

SimpleFilter::SimpleFilter(int sizeX, int sizeY, int bufferSize){
    _sizeX = sizeX;
    _sizeY = sizeY;

    _coeffX = new float[sizeX];
    _lastX = new float[sizeX-1]; // Doesnt need to store current value

    _coeffY = new float[sizeY];
    _lastY = new float[sizeY];

    _bufferSize = bufferSize;

    for(int i = 0; i < _sizeX-1; ++i){
        _lastX[i] = 0;
    }
    for(int i = 0; i < _sizeY; ++i){
        _lastY[i] = 0;
    }
}

void SimpleFilter::setCoefficients(const float* coeffX, const float* coeffY, const float gain){
    VectorOperations::copyVector(coeffX, _coeffX, _sizeX);
    VectorOperations::copyVector(coeffY, _coeffY, _sizeY);
    _gain = gain;
}

void SimpleFilter::filter(float *x, float *y){
    float sumY = 0;
    float sumX = 0;
    float result = 0;
    for(int i = 0; i < _bufferSize; ++i){
        sumY = 0;
        for(int j = 0; j < _sizeY; ++j){
            sumY += _lastY[j]*_coeffY[j];
        }
        sumX = x[i]*_coeffX[0];
        for(int j = 1; j < _sizeX; ++j){
            sumX += _lastX[j-1]*_coeffX[j];
        }
        result = -sumY + _gain*sumX;
        y[i] = result;
        VectorOperations::delayVector(_lastY, _lastY, 1, _sizeY, false);
        _lastY[0] = y[i];

        VectorOperations::delayVector(_lastX, _lastX, 1, _sizeX-1, false);
        _lastX[0] = x[i];
    }
    //VectorOperations::printVector(y, _bufferSize);

}
