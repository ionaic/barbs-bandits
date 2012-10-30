#ifndef _TOGGLE_BUTTON_H_
#define _TOGGLE_BUTTON_H_

#include <string>
#include "ImageElement.h"
#include "TextElement.h"
#include "Text.h"
#include "Button.h"

using namespace std;

class ToggleButton: public Button {
	public:
        ToggleButton() : Button() { this->_down = false; }
        ToggleButton(int x, int y) : Button(x, y) { this->_down = false; }
        ToggleButton(int x, int y, int w, int h) : Button(x, y, w, h) {
        	this->_down = false;
        	_image = new ImageElement(x, y, w, h);
        	Element::addChild(_image);
        	_text = new TextElement(x, y, w, h, 0, "");
        }
        ToggleButton(int x, int y, int w, int h, 
            string content, int size, ImageElement* i) : Button(x, y, w, h) {
            this->_down = false;
            _image = i;
            Element::addChild(_image);
            _text = new TextElement(x, y, w, h, size, content);
            Element::addChild(_text);
        }
        //~ToggleButton() { Button::~Button(); }
        void setText(string txt) { _text->setText(txt); }

	private:
	    bool _down;
	    TextElement* _text;
	    ImageElement* _image;
};
#endif
