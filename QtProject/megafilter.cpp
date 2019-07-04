#include "megafilter.h"

MegaFilter::MegaFilter(){

}

void MegaFilter::init(int buffers, int bufferSize){
    _buffers = buffers;
    _bufferSize = bufferSize;

    _filteredSignal = new float[_buffers*_bufferSize];
    _tempSignal1 = new float[_buffers*_bufferSize];
    _tempSignal2 = new float[_buffers*_bufferSize];
}

void MegaFilter::setEmpiricalVariables(int movingAverageSamples, float digitalThreshold, int mininumHigh){
    _movingAverageSamples = movingAverageSamples;
    _digitalThreshold = digitalThreshold;
    _mininumHigh = mininumHigh;
}

void MegaFilter::filter(float* x){

    _filterUnit->filter(x, _tempSignal1);
    // Remove older chunk, move and insert newest
    VectorOperations::shiftAndConcatenateVector(_filteredSignal, _filteredSignal, _tempSignal1, _buffers*_bufferSize, _bufferSize);
}

int MegaFilter::analyze(){
    int totalSize = _buffers*_bufferSize;
    // Saves previous states
    _states[0] = _states[1];
    _states[1] = _states[2];
    int count = 0;

    // Squares the vector
    VectorOperations::squareVector(_filteredSignal, _tempSignal1, _buffers*_bufferSize);
    
    // Averages the vector
    VectorOperations::averageVector(_tempSignal1, _tempSignal2, totalSize, _movingAverageSamples);

    // Takes maximun value of vector
    float max = VectorOperations::max(_tempSignal2, totalSize);

    // If max value is significant 
    if(max > (0.05)) {
        std::cout << "Max passed for " << _filterUnit->_tag << std::endl;
        // Scale the vector
        VectorOperations::scale(_tempSignal2, _tempSignal2, totalSize, 1/max);

        // Digitalize vector 
        VectorOperations::digitalizeVector(_tempSignal2, _tempSignal2, totalSize, _digitalThreshold, 1);

        // Cant start or end as a high, remove infinite signal
        if(false && _tempSignal2[0] == 1 &&  _tempSignal2[totalSize-1] == 1){
            _states[2] = false;
        }
        else{
            //Checks for range in the sequence
            int delta = 0;
            int prev = 0;
            for(int i = 1; i < totalSize; ++i){
                int current = _tempSignal2[i];
                if(current == 1){
                    count++;
                }
                delta += std::abs(prev-current);
                prev = current;
            }
            //std::cout << _filterUnit->_tag <<  " with Count:  " << count << ", Delta: " << delta << " and max: " << max <<std::endl;
            // Existance of a single signal in the block
            if(delta != 1 && delta < 10){
                // Count in range of pulse
                if(count > _mininumHigh && count < 2800){
                    std::cout << _filterUnit->_tag <<  " with Count:  " << count << ", Delta: " << delta << " and max: " << max <<std::endl;
                    _states[2] = true && !_states[1];
                }
                else{
                    _states[2] = false;
                }
            }
            else{
                _states[2] = false;
            }
        }
    }
    else{
        _states[2] = false;
    }

    // Checks for a hit
    
    bool hit = (_states[2]);
    return count * hit;
}
