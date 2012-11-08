/*! \file
This file contains the SliderBar class.
*/

#ifndef _SLIDERBAR_H_
#define _SLIDERBAR_H_

#include "../image/ImageElement.h"
#include "BoundedCounter.h"

class SliderBar : public BoundedCounter {
public:
	SliderBar(int x, int y, int width, int height, int value); /*!< /brief Constructor with starting values */
	void mouseDown(int x, int y);
	void mouseUp(int x, int y);
	void mouseMove(int x, int y, int dx, int dy);
	bool setValue(int value);

private:
	ImageElement* _imageE;
	void _update();
	bool _down;


};

#endif
