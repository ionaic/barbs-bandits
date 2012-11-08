#include "TextEdit.h"
#include "TextElement.h"
#include <string>

TextEdit::TextEdit(int x, int y, int width, int height, string txt) :
	TextElement(x,y,width,height,14,txt) {
    _inside = false;
}

void TextEdit::keyDown(int c) {
    if ( _inside ) {
        if (c==-1) {
            backspace();
        } else {
            setText(_text->getText()+char(c));
        }
    }
}

void TextEdit::backspace() {
    if ( _inside ) {
        string t = _text->getText();
        if (t.length() > 0) {
            t = t.substr(0,t.length()-1);
            setText(t);
        }
    }
}

void TextEdit::mouseDown(int x, int y) {
    if ( x < 0 || y < 0) {
        _inside = false;
        return;
    }
    vector<Element*>::iterator child = this->_children.begin();
    bool inside = (this->_width >= x && this->_height >= y);
    if (inside) { //if inside button
        if (0 != _mouseCallback ) //if element has a callback
            this->_mouseCallback(this,x,y);
        _inside = true;
        return;
    }
    _inside = false;
}
