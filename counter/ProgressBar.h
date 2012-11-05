/*! \file
This file contains the ProgressBar class.
*/

#ifndef _PROGRESSBAR_H_
#define _PROGRESSBAR_H_

#include "BoundedCounter.h"

class ProgressBar : public BoundedCounter {
public:
	ProgressBar(){ ProgressBar(0); }  /*!< \brief Default Constructor. */
	ProgressBar(int value) : BoundedCounter(value) {} /*!< /brief Constructor with starting value */

private:
	Element* _imageE;
	Element* _textE;


};

#endif
