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
#include "ToggleButton.h"
#include <iostream>
#include <vector>

using namespace std;

/*! \brief The class used to store a group of Checkboxes consisting of multiple ToggleButtons. Not yet implemented */
class CheckBox : public Element {
public:
    CheckBox(int x, int y, int width, int height, vector <string> buttons );
};
#endif
