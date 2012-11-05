/*! \file
This file contains the NumericCounter class.
*/

#ifndef _NUMERICCOUNTER_H_
#define _NUMERICCOUNTER_H_

#include "AbstractCounter.h"
#include "Image.h"
#include "Text.h"

/*! \brief An class used to display a simple numeric counter on a gui
 */
class NumericCounter : public AbstractCounter {
public:
	NumericCounter() { NumericCounter(0); }  /*!< \brief Default Constructor. */
	NumericCounter(int value) : AbstractCounter(value) {
		_imageE = new Image(_width, _height);
	};

	void clearResult();

private:
	Image * _imageE;
	Text * _textE;
};

#endif
