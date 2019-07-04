/**
 * \file   simplefilter.h
 *         Implements filtering in the frequency domain using difference equations
 * \author Roberto Gutierrez
 * \date   2019.06.15
 *
 * $Id: simplefilter.cpp $
 */

#ifndef SIMPLEFILTER_H
#define SIMPLEFILTER_H

#include "vectoroperations.h"
#include <iostream>
class SimpleFilter{
public:
    SimpleFilter(int sizeX, int sizeY, int bufferSize);
    void setCoefficients(const float* coeffX, const float* coeffY, const float gain);
    void filter(float* x, float* y);

    int _bufferSize;
    int _sizeY; // Filter memory for Y
    int _sizeX; //Filter memory for X
    float* _coeffX; // Coefficients for X, counting 0, for current value
    float* _coeffY; // Coefficients for Y, startin for y(n-1)
    float* _lastX; // Last values for X, sizeX-1
    float* _lastY; // Last values for Y
    float _gain;
};

#endif // SIPLEFILTER_H
