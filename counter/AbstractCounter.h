/*! \file
This file contains the AbstractCounter class.
*/
#ifndef _ABSTRACTCOUNTER_H_
#define _ABSTRACTCOUNTER_H_

#include "Element.h"

using namespace std;

//The end user shouldn't directly access this class. 

/*! \brief An internal class used to store Counter information

This class should not be accessed directly. Instead, all interactions should go through NumericalCounter, BoundedCounter, FractionalCounter, ProgressBar, or SliderBar.
*/
class AbstractCounter : public Element {
	public:
		AbstractCounter() {}; /*!< \brief Default Constructor. */
		AbstractCounter(int x, int y, int width, int height, int value); /*!< \brief simple constructor for x, y, width, height*/

		virtual bool setValue(int value); /*!< \brief Update the text stored and re-render it*/
		int getValue(); /*!< \brief Update the text stored and re-render it*/
		virtual void clearResult() {}; /*!< \brief override the clearResult method of element for the counters */
		AbstractCounter &operator++();

	protected:
		int _value;
};
#endif
