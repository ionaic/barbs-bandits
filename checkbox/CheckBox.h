/*! \file
	This file contains the Checkbox class.
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

/*! \brief The class used to store a group of Checkboxes consisting of multiple ToggleButtons.*/
class CheckBox : public Element {
public:
    CheckBox(int x, int y, int width, int height, vector <string> buttons );/*!< \brief Constructor.  Sets Elements x and y positions as well as width and height */
};
#endif
