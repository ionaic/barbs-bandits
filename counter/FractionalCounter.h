/*! \file
This file contains the FractionalCounter class.
*/

#ifndef _FRACTIONALCOUNTER_H_
#define _FRACTIONALCOUNTER_H_

#include "BoundedCounter.h"

class FractionalCounter : public BoundedCounter {
public:
	FractionalCounter(); /*!< \brief Default Constructor. */
	FractionalCounter(int x, int y, int width, int height, int value); /*!< /brief Constructor with starting values */
	~FractionalCounter();

private:
	Element* _textE;

};

#endif
