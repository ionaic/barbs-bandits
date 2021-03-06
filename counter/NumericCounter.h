/*! \file
This file contains the NumericCounter class.
*/

#ifndef _NUMERICCOUNTER_H_
#define _NUMERICCOUNTER_H_

#include "AbstractCounter.h"
#include "TextElement.h"
#include <cstdlib>

/*! \brief An class used to display a simple numeric counter on a gui
 */
class NumericCounter : public AbstractCounter {
public:
	NumericCounter(int x, int y, int width, int height, int value); /*!< \brief constructor that can be passed a value, xy coords, and width / height. */
	~NumericCounter();  /*!< \brief default destructor */
	bool setValue(int value);	/*!< \brief Override BoundedCounter's setValue. */
	NumericCounter &operator++(int); /*!< \brief ++ operator to increment the counter */
	NumericCounter &operator--(int); /*!< \brief -- operator to decrement the counter */

private:
	TextElement * _textE;
	void _update(); //forces the element to update
};

#endif
