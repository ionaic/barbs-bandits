/*! \file
This file contains the RadioButton class.
*/
#ifndef _RADIOBUTTON_H_
#define _RADIOBUTTON_H_

#include "CheckBox.h"
#include <vector>
#include <string>

using namespace std;

/*! \brief The class used to store a group of buttons consisting of multiple ToggleButtons.  Only one button may be active at any given time.*/
class RadioButton : public CheckBox {
    friend class DropDown;
public:
    RadioButton(int x, int y, int width, int height, vector <string> buttons);/*!< \brief Constructor.  Sets x and y position of Element along with height and width */
    RadioButton(int x, int y, int width, int height,
            vector <string> buttons,
            const char* up, const char* down);/*!< \brief Constructor.  Sets x and y position of Element along with height and width and button image*/
    void mouseDown(int x, int y); /*!< \brief Overrides the mouseDown call of Element */
    ToggleButton * getActive(); /*! \brief returns the active button */
};

#endif
