/*! \file
This file contains the ProgressBar class.
*/

#ifndef _BOUNDEDCOUNTER_H_
#define _BOUNDEDCOUNTER_H_

#include "AbstractCounter.h"

class ProgressBar : BoundedCounter {
public:
	ProgressBar() BoundedCounter();  /*!< \brief Default Constructor. */
	ProgressBar(int value) : BoundedCounter(value) {}; /*!< /brief Constructor with starting value */

private:
	Element* imageE;
	Element* textE;


};

#endif
