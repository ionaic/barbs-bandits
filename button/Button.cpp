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
    _imageE = new ImageElement(0, 0, width, height, i); //need to draw image first
    addChild(_imageE);
    _textE = new TextElement(0, 0, width, height, 0, "");
    addChild(_textE);
}

/*!Constructor sets x,y, width, height and text */
Button::Button(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height, string txt) : Element(x, y, width, height) {
    Pixel p(255, 255, 255, 127);
    Image i(width, height, p);
	_imageE = new ImageElement(0, 0, width, height, i); //need to draw image first
	addChild(_imageE);
	_textE = new TextElement(0, 0, width, height, 0, txt);
	addChild(_textE);
}

/*!Constructor sets x,y, width height and a background of an image */
Button::Button(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height, ImageElement* img) : Element(x, y, width, height) {
	_imageE = img;		//need to draw image first
	addChild(_imageE);
	_textE = new TextElement(0, 0, width, height);
	addChild(_textE);
}

/*!Sets the background image of a button*/
void Button::setBgIg(ImageElement* img) {
    Element::addChild(img);
    setDirty(true);
    img->setDirty(true);
}

/*!Sets the text of a button*/
void Button::setText(string txt) {
	_textE->setText(txt);
    _textE->setDirty(true);
    setDirty(true);
}
