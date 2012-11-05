/*! \file
This file contains the ProgressBar class.
*/

#ifndef _PROGRESSBAR_H_
#define _PROGRESSBAR_H_

#include "BoundedCounter.h"

class ProgressBar : BoundedCounter {
public:
	ProgressBar() BoundedCounter();  /*!< \brief Default Constructor. */
	ProgressBar(int value) : BoundedCounter(value); /*!< /brief Constructor with starting value */

private:
	Element* imageE;
	Element* textE;


};

#endif
