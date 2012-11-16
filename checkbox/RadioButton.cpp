#include "RadioButton.h"
#include "../checkbox/CheckBox.h"
#include "../togglebutton/ToggleButton.h"
#include <vector>
#include <string>

/*!Constructor.  Sets x and y position of Element along with height and width */
RadioButton::RadioButton(int x, int y, int width, int height,
        vector <string> buttons): CheckBox(x, y, width, height, buttons) {
}

/*!Overrides the mouseDown call of Element */
void RadioButton::mouseDown(int x, int y) {
    vector <Element*>::iterator child = _children.begin();
    bool inside = (this->_width >= x && this->_height >= y);
        if (inside) { //if inside button
            for (; _children.end() != child; child++) {
               ((ToggleButton *)(*child))->setDown(false);
            }
        }
    setDirty(true);
    Element::mouseDown(x, y);
}
