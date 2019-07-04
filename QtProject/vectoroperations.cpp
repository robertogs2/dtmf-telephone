#include "vectoroperations.h"

// Not tested
void VectorOperations::copyVector(const float *vectorA, float *vectorB, int length){
    for(int i = 0; i < length; ++i){
        vectorB[i] = vectorA[i];
    }
}

void VectorOperations::squareVector(float *vectorA, float *vectorB, int length){
    for(int i = 0; i < length; ++i){
        vectorB[i] = vectorA[i]*vectorA[i];
    }
}

void VectorOperations::averageVector(float *vectorA, float *vectorB, int length, int m){
    // Leave number odd evertime
    if(m & 1 == 0){
        m -= 1;
    }
    int n = (m-1) >> 1; // Samples to each side to get


    float sum = 0;
    for(int i = 0; i <= n; ++i){
        sum += vectorA[i];
    }
    // Start iteration
    int counter = n+1;
    int i = 0;
    while(i<=n){
        vectorB[i] = sum/counter;
        counter++;
        sum += vectorA[i+n+1];
        ++i;
    }
    ++i;
    // Middle iteration
    while(i+n<length){
        sum -= vectorA[i-n-1];
        sum += vectorA[i+n];
        vectorB[i] = sum/counter;
        ++i;
    }

    // End iteration
    while(i<length){
        counter--;
        sum -= vectorA[i-n-1];
        vectorB[i] = sum/counter;
        ++i;
    }
}

void VectorOperations::printVector(float *vectorA, int length){
    //std :: cout << length << std::endl;
    for(int i = 0; i < length; ++i){
        std::cout << vectorA[i] << " ";
    }
    std::cout << std::endl;
}

float VectorOperations::average(float *vectorA, int length){
    float sum = 0;
    for(int i = 0; i < length; ++i){
        sum += vectorA[i];
    }
    return sum/length;
}

float VectorOperations::max(float *vectorA, int length){
    float max = 0;
    for(int i = 0; i < length; ++i){
        if(vectorA[i] > max) max=vectorA[i];
    }
    return max;
}

void VectorOperations::scale(float *vectorA, float* vectorB, int length, float scale){
    for(int i = 0; i < length; ++i){
        vectorB[i]=vectorA[i]*scale;
    }
}

int VectorOperations::digitalizeVector(float *vectorA, float *vectorB, int length, float limit, float value){
    int count = 0;
    for(int i = 0; i < length; ++i){
        if(vectorA[i] >= limit){
            vectorB[i] = value;
            count++;
        }
        else vectorB[i] = 0;
    }
    return count;
}

// Moves vector to left and fills empty space with vectorC, vectorC.length = lengthSmall is needed
void VectorOperations::shiftAndConcatenateVector(float *vectorA, float *vectorB, float *vectorC, int lengthLarge, int lengthSmall){
    int i = 0;
    for(; i+lengthSmall < lengthLarge; ++i){
        vectorB[i] = vectorA[i+lengthSmall];
    }
    for(int j = 0;i < lengthLarge;++i){
        vectorB[i] = vectorC[j];
        ++j;
    }
}

// Moves vector to left and fills empty space with nothing, lengthSmall is the shift
void VectorOperations::shiftVector(float *vectorA, float *vectorB, int length, int amount){
    int i = 0;
    for(; i+amount < length; ++i){
        vectorB[i] = vectorA[i+amount];
    }
}

// Not tested
void VectorOperations::delayVector(float *vectorA, float *vectorB, int delay, int length, bool fill){
    int i = length-1;
    for(; i-delay >= 0; --i){
        vectorB[i] = vectorA[i-delay];
    }
    // Fills the rest with zeros
    if(fill){
        for(;i>=0;--i){
            vectorB[i] = 0;
        }
    }
}

int VectorOperations::countOnes(float* vectorA, int length){
    int counter = 0;
    for(int i = 0; i < length; ++i){
        counter += vectorA[i]==1;
    }
    return counter;
}

int VectorOperations::averageDigitalizeCounterVector(float* vectorA, int length, int m, float limit){
    int globalCounter = 0;
    // Leave number odd evertime
    if(m & 1 == 0){
        m -= 1;
    }
    int n = (m-1) >> 1; // Samples to each side to get


    float sum = 0;
    for(int i = 0; i <= n; ++i){
        sum += vectorA[i];
    }
    // Start iteration
    int counter = n+1;
    int i = 0;
    while(i<=n){
        globalCounter += (sum/counter) >= limit; // ONE RESULT
        counter++;
        sum += vectorA[i+n+1];
        ++i;
    }
    ++i;
    // Middle iteration
    while(i+n<length){
        sum -= vectorA[i-n-1];
        sum += vectorA[i+n];
        globalCounter += (sum/counter) >= limit; // ONE RESULT
        ++i;
    }

    // End iteration
    while(i<length){
        counter--;
        sum -= vectorA[i-n-1];
        globalCounter += (sum/counter) >= limit; // ONE RESULT
        ++i;
    }

    return globalCounter;
}

