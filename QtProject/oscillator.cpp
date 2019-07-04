#include "oscillator.h"

oscillator::oscillator():
	sampleRate_(0),
  	bufferSize_(0),
  	amplitude_(0),
  	frequency_(0){
}

oscillator::~oscillator(){
	//Should remove signal
	delete signal_;
}

void oscillator::init(const int sampleRate, const int bufferSize, const float amplitude, const float frequency){
	updateVariables(sampleRate, bufferSize, amplitude, frequency);
	active_=true;
	signal_ = new float[bufferSize_];
}

void oscillator::calculateConstants(){
	w_  = 2*M_PI*frequency_/float(sampleRate_);
	y1_ =0;
	y2_ =-amplitude_*sin(w_);
	a1_ =2*cos(w_);
}

void oscillator::generateSignal(){
	for(int i = 0; i < bufferSize_; ++i){
		signal_[i]=active_ ? a1_*y1_-y2_ : 0; //If oscillator is active then use it
		y2_=y1_;
		y1_=signal_[i];
	}
}

float* oscillator::getSignal(){
	return signal_;
}

void oscillator::updateVariables(const int sampleRate, const int bufferSize, const float amplitude, const float frequency){
	sampleRate_ = sampleRate;
	bufferSize_ = bufferSize;
	amplitude_ = amplitude;
	frequency_ = frequency;
	calculateConstants();
}


void oscillator::setSampleRate(const int sampleRate){
	sampleRate_=sampleRate;
	calculateConstants();
}

void oscillator::setBufferSize(const int bufferSize){
	bufferSize_=bufferSize;
	calculateConstants();
}

void oscillator::setAmplitude(const float amplitude){
	amplitude_=amplitude;
	calculateConstants();
}

void oscillator::setFrequency(const float frequency){
	frequency_=frequency;
	calculateConstants();
}

void oscillator::setActive(bool active){
	active_=active;
}

bool oscillator::getActive(){
	return active_;
}
