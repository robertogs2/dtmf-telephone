/**
 * \file   oscillator.h
 *         Implements a frequency oscillator
 * \author Roberto Gutierrez-Sanchez
 * \date   2019.27.04
 *
 */

#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include <math.h>
#include <iostream>
class oscillator{

public:

    /**
     * Constructor
     */
    oscillator();

    /**
     * Destructor
     */
    ~oscillator();

    /**
     *  Initializer for current oscilator variables
     */

    void init(const int sampleRate, const int bufferSize, const float amplitude, const float frequency);

    /**
     * Calculates next batch of signal
     */

    void generateSignal();

    float* getSignal();

    void setSampleRate(const int sampleRate);
    void setBufferSize(const int bufferSize);
    void setAmplitude(const float amplitude);
    void setFrequency(const float frequency);

    void updateVariables(const int sampleRate, const int bufferSize, const float amplitude, const float frequency);
    
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
   * Amplitude
   */

  float amplitude_;

  /**
   * Frequency for signal
   */

  float frequency_;

  /**
   * Actual oscilation signal
   */

  float* signal_;



private:

  void calculateConstants();

  float w_;
  float a1_;
  float y1_; 
  float y2_;
  bool active_;

};

#endif // OSCILLATOR_H