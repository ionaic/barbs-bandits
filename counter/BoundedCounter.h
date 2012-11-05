/*! \file
This file contains the BoundedCounter class.
*/

#ifndef _BOUNDEDCOUNTER_H_
#define _BOUNDEDCOUNTER_H_

#include "AbstractCounter.h"

class BoundedCounter : AbstractCounter {
public:
	BoundedCounter();  /*!< \brief Default Constructor. */
	BoundedCounter(int value) : AbstractCounter(value) {};

	void setMax(int max) { _max = max; }
	void setValue(int value) { if (value < _max) _value=value}


private:
	int _max;
	Element* imageE;
	Element* textE;


};

#endif
