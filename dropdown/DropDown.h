/*! \file
This file contains the DropDown class
*/

#ifndef _DROPDOWN_H_
#define _DROPDOWN_H_

#include "ToggleButton.h"
#include "RadioButton.h"
#include <string>


class DropDown: public Element {
public:
    /*! \brief Constructor that sets x and y coords, width, height, and gives a list of options */
    DropDown(unsigned int x, unsigned int y,
            unsigned int width, unsigned int height, vector <string> menuList);
    /*! \brief Constructor that sets x and y coords, width, height, and gives a list of options, includes image */
    DropDown(unsigned int x, unsigned int y,
                unsigned int width, unsigned int height, vector <string> menuList,
                const char* up, const char* down);
    /*! \brief Dropdown destructor deletes the RadioButton */
    ~DropDown();
    void mouseDown(int x, int y); /*! \brief overrides elements mouseDown function */

private:
    bool _isMenu;
    void _switch(); //switches from button to menu
    ToggleButton * _selected; //button to be displayed when menu is collapsed
    RadioButton * _menu; //full menu to be displayed
    int _prevPos;
};

#endif
