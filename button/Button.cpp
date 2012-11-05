#include <string>
#include "../image/Image.h"
#include "../text/Text.h"
#include "../element/Element.h"
#include "../image/ImageElement.h"
#include "../text/TextElement.h"
#include "Button.h"
#include <iostream>

/*!Default constructor creates an empty instance of the class. */
Button::Button() : Element() {}

/*!Constructor sets x,y position according to arguments and sizes to zero. */
Button::Button(unsigned int x, unsigned int y) {
	Button(x, y, 0, 0);
}

/*!Constructor sets x,y position, width and heigh according to arguments. Leaves text empty */
Button::Button(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height) {
	Button(x, y, width, height, "");
}

/*!Constructor sets x,y, width, heigh and text */
Button::Button(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height, string txt) : Element(x, y, width, height) {
	int h = height>>1;
	int w = (width/txt.size()<<1);
	unsigned int size;
	if (h > w) {
		size = h;
	}else{
		size = w;
	}

	_imageE = new ImageElement(0, 0, width, height); //need to draw image first
	addChild(_imageE);
	_textE = new TextElement(0, 0, width, height, size, txt);
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
}

/*!Sets the text of a button*/
void Button::setText(string txt) {
	_textE->setText(txt);
}
