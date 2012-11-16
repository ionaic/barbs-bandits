/*! \file
This file contains the SliderBar class.
*/

#ifndef _SLIDERBAR_H_
#define _SLIDERBAR_H_

#include "ImageElement.h"
#include "BoundedCounter.h"

class SliderBar : public BoundedCounter {
public:
	SliderBar(int x, int y, int width, int height, int value); /*!< /brief Constructor with starting values */
	void mouseDown(int x, int y); /*!< /brief Override elements mouseDown */
	void mouseUp(int x, int y); /*!< /brief Override elements mouseUp */
	void mouseMove(int x, int y, int dx, int dy); /*!< /brief Override elements mouseMove */
	bool setValue(int value); /*!< \brief Override AbstractCounter's setValue. */

private:
	ImageElement* _imageE; //internal image for sliderBar
	void _update(); //forces the element to update
	bool _down; //state of the mouseButton


};

#endif
