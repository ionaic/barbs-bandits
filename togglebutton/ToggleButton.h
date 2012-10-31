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
        }
        ToggleButton(int x, int y, int w, int h, string txt) : Button(x, y, w, h, txt) {
        	cout << "creating tbutton" << endl;
        	this->_down = false;
        }
        ToggleButton(int x, int y, int w, int h, 
            string content, int size, ImageElement* i) : Button(x, y, w, h, i) {
            this->_down = false;
        }
        //~ToggleButton() { Button::~Button(); }

	private:
	    bool _down;
};
#endif
