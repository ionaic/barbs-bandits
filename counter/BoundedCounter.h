/*! \file
This file contains the BoundedCounter class.
*/

#ifndef _BOUNDEDCOUNTER_H_
#define _BOUNDEDCOUNTER_H_

#include "AbstractCounter.h"

class BoundedCounter : public AbstractCounter {
public:
	BoundedCounter(int x, int y, int width, int height, int value); /*< /brief Constructor with starting value. Sets maximum to 100. */
	BoundedCounter(int x, int y, int width, int height,
	        int value, int max);  /*< /brief Constructor with starting value and maximum value*/
	void setMax(int max); /*< /brief Set maximum value of the counter */
	virtual bool setValue(int value); /*< /brief Set value of the counter. Must be less than maximum */
	BoundedCounter &operator++(int);

protected:
	int _max;
};

#endif
