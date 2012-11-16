#include "DropDown.h"

/*! Dropdown constructor */
DropDown::DropDown(unsigned int x, unsigned int y,
        unsigned int width, unsigned int height,
        vector <string> menuList): Element(x, y, width, height) {
    //create the expanded menu.
    this->_menu = new RadioButton(0, 0, width, height, menuList);
    this->_selected = (ToggleButton *) _menu->_children[
                      _menu->_children.size() - 1];
    this->_height = _menu->_children[
                    _menu->_children.size() - 1]->height();
    _prevPos = this->_selected->_yCoord;
    this->_selected->setY(0);
    addChild(this->_selected);

    _isMenu = false;
}

/*! Dropdown destructor */
DropDown::~DropDown() {
    delete _menu;
}

/*! overrides element's mouseDown function */
void DropDown::mouseDown(int x, int y) {
    bool inside = (this->_width >= x && this->_height >= y);
    if (inside) {
        if (_isMenu) {
            _menu->mouseDown(x, y);
            _selected = _menu->getActive();
        }
        _switch();
    }
}

//switches between the button and menu */
void DropDown::_switch() {
    //if it's in a button
    _children.clear();
    if (!_isMenu) {
        this->_height = _menu->height();
        this->_selected->setY(_prevPos);
        addChild(_menu);
    }
    else {
        this->_height = _selected->height();
        _prevPos = this->_selected->_yCoord;
        this->_selected->setY(0);
        addChild(_selected);
    }
    _isMenu = !_isMenu;
}


