/*! \file
This file contains the NumericCounter class.
*/

#ifndef _NUMERICCOUNTER_H_
#define _NUMERICCOUNTER_H_

#include "AbstractCounter.h"

class NumericCounter : AbstractCounter {
public:
	NumericCounter();  /*!< \brief Default Constructor. */
	NumericCounter(int value) : AbstractCounter(value) {};

	void clearResult();

private:
	Element * imageE;
	Element * textE;


};

#endif
