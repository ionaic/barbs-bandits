#include "Dropdown.h"

Dropdown::Dropdown(unsigned int x, unsigned int y, unsigned int width, unsigned int height, vector<Element*> &children) : Element(x, y, width, height) {
    unsigned int childY = 0, childHeight = ;
    for (vector<Element*>::iterator itr = children.begin(); children.end() != itr; itr++) {
        this->_children.push_back(new TextElement(*itr));
    }
}

void Dropdown::dd_click() {
    if (this->_clicked) {
        
    }
}
