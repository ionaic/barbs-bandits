/*! \file
This file contains the SliderBar class.
*/

#ifndef _SLIDERBAR_H_
#define _SLIDERBAR_H_

#include "BoundedCounter.h"

class SliderBar : public BoundedCounter {
public:
	SliderBar() : BoundedCounter() {};  /*!< \brief Default Constructor. */
	SliderBar(int value) : BoundedCounter(value) {}; /*!< /brief Constructor with starting values */

private:
	Element* imageE;
	Element* textE;


};

#endif
