#include <string>
#include "../image/Image.h"
#include "../text/Text.h"
#include "../element/Element.h"
#include "../image/ImageElement.h"
#include "../text/TextElement.h"
#include "Button.h"

/*!Constructor sets x,y position, width and heigh according to arguments. Leaves text empty */
Button::Button(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height): Element(x, y, width, height) {
    Pixel p(255, 255, 255, 127);
    Image i(width, height, p);
    _imageUp = new ImageElement(0, 0, width, height, i); //need to draw image first
    Pixel p2(205, 205, 205, 127);
    Image i2(width, height, p2);
    _imageDown = new ImageElement(0, 0, width, height, i2); //need to draw image first
    _textE = new TextElement(0, 0, width, height, 0, "");
    _textE->setZ(0);
    addChild(_textE);
    _down = false;
}

/*!Constructor sets x,y, width, height and text */
Button::Button(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height, string txt) : Element(x, y, width, height) {
    Pixel p(255, 255, 255, 127);
    Image i(width, height, p);
	_imageUp = new ImageElement(0, 0, width, height, i); //need to draw image first
	Pixel p2(205, 205, 205, 127);
	Image i2(width, height, p2);
	_imageDown = new ImageElement(0, 0, width, height, i2); //need to draw image first
	_textE = new TextElement(0, 0, width, height, 0, txt);
	_textE->setZ(0);
	addChild(_textE);
	_down = false;
}

/*!Constructor sets x,y, width height and a background of an image */
Button::Button(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height, const char* up_file, const char* down_file,
		string text) : Element(x, y, width, height) {
	setUpImage(width, height, up_file);
	setDownImage(width, height, down_file);
	int offset_w = width / 8;
	int offset_h = height / 4;
	_textE = new TextElement(offset_w, offset_h,
	        width - ( offset_w ) , height - (offset_h ), 0, text);
    _textE->setZ(0);
	addChild(_textE);
    _down = false;
}

/*!Sets the background image of a button*/
void Button::setUpImage(int width, int height, const char* up_file) {
	_imageUp = new ImageElement(0, 0, width, height, up_file);		//need to draw image first
    _imageUp->setZ(-1);
    Element::addChild(_imageUp);
    _imageUp->setDirty(true);
}

void Button::setDownImage(int width, int height, const char* down_file) {
    _imageDown = new ImageElement(0, 0, width, height, down_file);      //need to draw image first
    _imageDown->setZ(-1);
}

/*!Sets the text of a button*/
void Button::setText(string txt) {
	_textE->setText(txt);
    _textE->setDirty(true);
}

void Button::_switch() {
    this->_children.clear();
    _down = !_down;
    if (_down)
        addChild(_imageDown);
    else
        addChild(_imageUp);
    addChild(_textE);
    if (this->_textE)
        _textE->setDirty(true);
}

/*! Tests if the mouse click down at (x, y) is within the element. */
void Button::mouseDown(int x, int y) {
    if ( x < 0 || y < 0) return;
    bool inside = (this->_width >= x && this->_height >= y);
    if (inside) { //if inside button
        if (0 != _mouseCallback ) //if element has a callback
            this->_mouseCallback(this,x,y);
        _switch();
        return;
    }
}

/*! Tests if the mouse click up at (x, y) is within the element. */
void Button::mouseUp(int x, int y) {
    if ( x < 0 || y < 0) return;
    bool inside = (this->_width >= x && this->_height >= y);
    if (inside) { //if inside button
        if (0 != _mouseUpCallback ) //if element has a callback
            this->_mouseUpCallback(this,x,y);
        _switch();
        return;
    }
}
