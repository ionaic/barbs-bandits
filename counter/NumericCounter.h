/*! \file
This file contains the NumericCounter class.
*/

#ifndef _NUMERICCOUNTER_H_
#define _NUMERICCOUNTER_H_

#include "AbstractCounter.h"
#include "ImageElement.h"
#include "TextElement.h"
#include <cstdlib>

/*! \brief An class used to display a simple numeric counter on a gui
 */
class NumericCounter : public AbstractCounter {
public:
	NumericCounter();  /*!< \brief Default Constructor. */
	NumericCounter(int value); /*!< \brief constructor that can be passed a value. */
	~NumericCounter();  /*!< \brief default destructor */
	bool setValue(int value);	/*!< \brief Override AbstractCounter's setValue. */

private:
	ImageElement * _imageE;
	TextElement * _textE;
};

#endif
