/*! \file
This file contains the BoundedCounter class.
*/

#ifndef _BOUNDEDCOUNTER_H_
#define _BOUNDEDCOUNTER_H_

#include "AbstractCounter.h"

class BoundedCounter : public AbstractCounter {
public:
	BoundedCounter() { BoundedCounter(0); }  /*!< \brief Default Constructor. Sets value to 0 and maximum to 100. */
	BoundedCounter(int value) { BoundedCounter(value,100); } /*< /brief Constructor with starting value. Sets maximum to 100. */

	BoundedCounter(int value, int max) : AbstractCounter(value) { _max = max;} /*< /brief Constructor with starting value and maximum value*/

	void setMax(int max) { _max = max; } /*< /brief Set maximum value of the counter */

	bool setValue(int value) {
		if (value < _max) {
			_value=value;
			return true;
		}
		else {
			return false;
		}
	} /*< /brief Set value of the counter. Must be less than maximum */

	~BoundedCounter() {
		//Delete stuff?
	}


protected:
	int _max;
	Element* imageE;
	Element* textE;


};

#endif
