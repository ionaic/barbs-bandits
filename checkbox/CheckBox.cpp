#include "CheckBox.h"
#include "../element/Element.h"
#include "../togglebutton/ToggleButton.h"
#include <vector>
#include <string>


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
