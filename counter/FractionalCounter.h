/*! \file
This file contains the FractionalCounter class.
*/

#ifndef _FRACTIONALCOUNTER_H_
#define _FRACTIONALCOUNTER_H_

#include "BoundedCounter.h"

class FractionalCounter : BoundedCounter {
public:
	FractionalCounter() BoundedCounter();  /*!< \brief Default Constructor. */
	FractionalCounter(value) : BoundedCounter(value); /*!< /brief Constructor with starting values */

private:
	Element* imageE;
	Element* textE;


};

#endif
