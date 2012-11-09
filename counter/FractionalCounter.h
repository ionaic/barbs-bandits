/*! \file
This file contains the FractionalCounter class.
*/

#ifndef _FRACTIONALCOUNTER_H_
#define _FRACTIONALCOUNTER_H_

#include "BoundedCounter.h"
#include "../text/TextElement.h"

class FractionalCounter : public BoundedCounter {
public:
	FractionalCounter(int x, int y, int width, int height, int value, int max); /*!< /brief Constructor with starting values */
	~FractionalCounter();
	FractionalCounter &operator++(int);
	FractionalCounter &operator--(int);

private:
	TextElement* _textE;
	void _update();

};

#endif
