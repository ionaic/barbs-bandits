/*! \file
This file contains the ProgressBar class.
*/

#ifndef _PROGRESSBAR_H_
#define _PROGRESSBAR_H_

#include "BoundedCounter.h"
#include "ImageElement.h"

class ProgressBar : public BoundedCounter {
public:
	ProgressBar(int x, int y, int width, int height, int value); /*!< /brief Constructor with starting value */
	bool setValue(int value); /*!< /brief sets the value and checks to ensure it's < max value */
	ProgressBar &operator++(int); /*!< \brief ++ operator to increment the counter */
	ProgressBar &operator--(int); /*!< \brief -- operator to decrement the counter */

private:
	ImageElement* _imageE;
    void _update(); //forces the element to update
};

#endif
