/*! \file
This file contains the SliderBar class.
*/

#ifndef _SLIDERBAR_H_
#define _SLIDERBAR_H_

#include "BoundedCounter.h"

class SliderBar : BoundedCounter {
public:
	SliderBar() BoundedCounter();  /*!< \brief Default Constructor. */
	SliderBar(value) : BoundedCounter(value); /*!< /brief Constructor with starting values */

private:
	Element* imageE;
	Element* textE;


};

#endif
