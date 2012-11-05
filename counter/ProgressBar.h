/*! \file
This file contains the ProgressBar class.
*/

#ifndef _PROGRESSBAR_H_
#define _PROGRESSBAR_H_

#include "BoundedCounter.h"
#include "../image/ImageElement.h"

class ProgressBar : public BoundedCounter {
public:
	ProgressBar(int x, int y, int width, int height, int value); /*!< /brief Constructor with starting value */
	bool setValue(int value); /*! /brief sets the value and checks to ensure it's < max value */
	void _update();
	ProgressBar &operator++(int);
	ProgressBar &operator--(int);

private:
	ImageElement* _imageE;
};

#endif
