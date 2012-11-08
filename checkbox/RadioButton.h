/*! \file
    This file contains the Checkbox class. This class is not yet implemented as per our iteration schedule.
*/
#ifndef _RADIOBUTTON_H_
#define _RADIOBUTTON_H_

#include "CheckBox.h"
#include <vector>
#include <string>

using namespace std;

/*! \brief The class used to store a group of Checkboxes consisting of multiple ToggleButtons. */
class RadioButton : public CheckBox {
public:
    RadioButton(int x, int y, int width, int height, vector <string> buttons);
    void mouseDown(int x, int y);
};

#endif
