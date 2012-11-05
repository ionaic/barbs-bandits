/*! \file
This file contains the FractionalCounter class.
*/

#ifndef _FRACTIONALCOUNTER_H_
#define _FRACTIONALCOUNTER_H_

#include "BoundedCounter.h"

class FractionalCounter : public BoundedCounter {
public:
	FractionalCounter() : BoundedCounter() {};  /*!< \brief Default Constructor. */
	FractionalCounter(int value) : BoundedCounter(value) {}; /*!< /brief Constructor with starting values */

private:
	Element* imageE;
	Element* textE;

};

#endif
