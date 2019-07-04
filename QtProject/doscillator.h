/**
 * \file   doscillator.h
 */

#ifndef DOSCILLATOR_H
#define DOSCILLATOR_H

#include <math.h>
#include <iostream>

class doscillator{
public:
    public:

    /**
     * Constructor
     */
    doscillator();

    /**
     * Destructor
     */
    ~doscillator();

    /**
     *  Initializer for current oscilator variables
     */

    void init(const int sampleRate, const int bufferSize, const float amplitudeZero, 
    			const float frequencyZero, const float amplitudeOne, const float frequencyOne);

    void updateVariables(const int sampleRate, const int bufferSize,
                         const float amplitudeZero, const float frequencyZero,
                         const float amplitudeOne, const float frequencyOne);

    /**
     * Calculates next batch of signal
     */

    void generateSignal();
    float* getSignal();

    // b to choose between both
    template<bool b>
    void setAmplitude(const float amplitude);

    void setFrequency(const float frequencyZero, const float frequencyOne);

    void setBufferSize(const int bufferSize);
    void setSampleRate(const int sampleRate);

    void setActive(bool active);
    bool getActive();

protected:
	/**
   * Sample rate
   */
  int sampleRate_;

  /**
   * Buffer size
   */
  int bufferSize_;

  /**
   * Amplitudes
   */

  float amplitudeZero_;
  float amplitudeOne_;

  /**
   * Frequency for signal
   */

  float frequencyZero_;
  float frequencyOne_;

  /**
   * Actual oscilation signal
   */

  float* signal_;


private:

  void calculateConstants();

  float wZero_;
  float a1Zero_;
  float y1Zero_; 
  float y2Zero_;

  float wOne_;
  float a1One_;
  float y1One_; 
  float y2One_;

  bool active_;

};

#endif // DOSCILLATOR_H
