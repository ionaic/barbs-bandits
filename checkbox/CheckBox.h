/*! \file
	This file contains the Checkbox class. This class is not yet implemented as per our iteration schedule.
*/
#ifndef _CHECKBOX_H_
#define _CHECKBOX_H_

#include "Element.h"
#include "Text.h"
#include "Image.h"
#include "ImageElement.h"
#include "TextElement.h"
#include <iostream>

using namespace std;

/*! \brief The class used to store a group of Checkboxes consisting of multiple ToggleButtons. Not yet implemented */
class CheckBox : public Element {
    public:
        CheckBox() : Element() { cout << "Checkbox is not yet implemented" << endl; }
        CheckBox(unsigned int x, unsigned int y) : Element(x, y) { cout << "Checkbox is not yet implemented" << endl;}
};
#endif
