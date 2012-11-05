/*! \file
This file contains the BoundedCounter class.
*/

#ifndef _BOUNDEDCOUNTER_H_
#define _BOUNDEDCOUNTER_H_

#include "AbstractCounter.h"

class BoundedCounter : AbstractCounter {
public:
	BoundedCounter() : AbstractCounter();  /*!< \brief Default Constructor. */
	BoundedCounter(int value) : AbstractCounter(value); /*< /brief Constructor with starting value */

	void setMax(int max) { _max = max; } /*< /brief Set maximum value of the counter */

	bool setValue(int value) {
		if (value < _max) {
			_value=value;
			return true
		}else{
			return false
		}
	} /*< /brief Set value of the counter. Must be less than maximum */


private:
	int _max;
	Element* imageE;
	Element* textE;


};

#endif
