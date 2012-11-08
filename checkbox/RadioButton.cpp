#include "RadioButton.h"
#include "../checkbox/CheckBox.h"
#include "../togglebutton/ToggleButton.h"
#include <vector>
#include <string>


RadioButton::RadioButton(int x, int y, int width, int height,
        vector <string> buttons): CheckBox(x, y, width, height, buttons) {
}

void RadioButton::mouseDown(int x, int y) {
    vector <Element*>::iterator child = _children.begin();
    bool inside = (this->_width >= x && this->_height >= y);
        if (inside) { //if inside button
            for (; _children.end() != child; child++) {
               ((ToggleButton *)(*child))->setDown(false);
            }
        }
    Element::mouseDown(x, y);
}
