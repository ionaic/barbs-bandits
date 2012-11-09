#include "Dropdown.h"
/* Notes for myself:
 *  [X] create with a vector of strings, autopopulate with dynamically
 *      allocated text elements
 *  [ ] auto size text?
 *  [X] auto allocate the height of the text elements
 *  [X] auto zIndex by order (to preserve order in child array)
 *  [ ] callback registering via Dropdown, not children
 *  [ ] animation/updating when clicked
 */

Dropdown::Dropdown(unsigned int x, unsigned int y, unsigned int width, unsigned int height, vector<std::string> &children) : Element(x, y, width, height) {
    unsigned int childY = 0, childHeight = (unsigned int)(height / children.size()), childZ = 0; 
    TextElement *curChild;
    for (vector<Element*>::iterator itr = children.begin(); children.end() != itr; itr++) {
        curChild = new TextElement(0, childY, width, childHeight,*itr);
        curChild->setZ(childZ++);
        childY += childHeight;
        this->_children.push_back(curChild);
    }
    this->_unclicked = this->_children[0];
}

void Dropdown::dd_click(std::string label) {
    if (this->_clicked) {
        
    }
}
