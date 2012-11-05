/*! \file
This file contains the SliderBar class.
*/

#ifndef _SLIDERBAR_H_
#define _SLIDERBAR_H_

#include "BoundedCounter.h"

class SliderBar : public BoundedCounter {
public:
	SliderBar() { SliderBar(0,0,0,0,0); }  /*!< \brief Default Constructor. */
	SliderBar(int x, int y, int width, int height, int value) : BoundedCounter(x,y,width,height,value) {} /*!< /brief Constructor with starting values */

private:
	Element* imageE;
	Element* textE;


};

#endif
