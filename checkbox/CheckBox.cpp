#include "CheckBox.h"
#include "../element/Element.h"
#include "../togglebutton/ToggleButton.h"
#include <vector>
#include <string>

/*!Constructor.  Sets Elements x and y positions as well as width and height */
CheckBox::CheckBox(int x, int y, int width, int height, vector <string> buttons ): Element(x, y, width, height) {
    int y1 = 0;
    int numBoxes = buttons.size();
    for (int i = numBoxes - 1; i >= 0; i--) {
        int bHeight = height / numBoxes;
        ToggleButton * _tb = new ToggleButton(0, y1, width, bHeight - 1, buttons[i]);
        y1 += bHeight;
        Element::addChild( _tb);
    }
}

/*!Constructor.  Sets Elements x and y positions as well as width and height and images */
CheckBox::CheckBox(int x, int y, int width, int height,
        vector <string> buttons, const char* up, const char* down ): Element(x, y, width, height) {
    int y1 = 0;
    int numBoxes = buttons.size();
    for (int i = numBoxes - 1; i >= 0; i--) {
        int bHeight = height / numBoxes;
        ToggleButton * _tb = new ToggleButton(0, y1, width, bHeight - 1, up, down, buttons[i]);
        y1 += bHeight;
        Element::addChild( _tb);
    }
}

void CheckBox::registerMouseDownCallback(int item, mouseDownCallback_t func) {
    if ( item < _children.size() )
        _children[_children.size()-item-1]->registerMouseDownCallback(func);
}
