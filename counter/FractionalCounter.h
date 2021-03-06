/*! \file
This file contains the FractionalCounter class.
*/

#ifndef _FRACTIONALCOUNTER_H_
#define _FRACTIONALCOUNTER_H_

#include "BoundedCounter.h"
#include "TextElement.h"

class FractionalCounter : public BoundedCounter {
public:
	FractionalCounter(int x, int y, int width, int height, int value, int max); /*!< \brief Constructor with starting values */
	~FractionalCounter(); /*!< \brief default destructor */
	FractionalCounter &operator++(int); /*!< \brief ++ operator to increment the counter */
	FractionalCounter &operator--(int); /*!< \brief -- operator to decrement the counter */

private:
	TextElement* _textE;
	void _update(); //forces an update on the element

};

#endif
