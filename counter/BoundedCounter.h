/*! \file
This file contains the BoundedCounter class.
*/

#ifndef _BOUNDEDCOUNTER_H_
#define _BOUNDEDCOUNTER_H_

#include "AbstractCounter.h"

class BoundedCounter : public AbstractCounter {
public:
<<<<<<< HEAD
	BoundedCounter() : AbstractCounter() {};  /*!< \brief Default Constructor. */
	BoundedCounter(int value) : AbstractCounter(value) {}; /*< /brief Constructor with starting value */
=======
	BoundedCounter() { BoundedCounter(0); }  /*!< \brief Default Constructor. */
	BoundedCounter(int value) : AbstractCounter(value) {} /*< /brief Constructor with starting value */
>>>>>>> b0815e582c9168945838ff658128ec6f5fb42453

	void setMax(int max) { _max = max; } /*< /brief Set maximum value of the counter */

	bool setValue(int value) {
		if (value < _max) {
			_value=value;
			return true;
<<<<<<< HEAD
		}else{
=======
		}
		else{
>>>>>>> b0815e582c9168945838ff658128ec6f5fb42453
			return false;
		}
	} /*< /brief Set value of the counter. Must be less than maximum */


private:
	int _max;
	Element* imageE;
	Element* textE;


};

#endif
