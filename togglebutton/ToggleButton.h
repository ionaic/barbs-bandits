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
        //~ToggleButton() { ~Button(); }
		void mouseInput(int x, int y) {
			if ( x < 0 || y < 0) return;
			bool inside = (this->_width >= x && this->_height >= y);
			cout << "Inside tbutton" << endl;
			if (inside) { //if inside button
				_down = !_down;
				if (0 != _mouseCallback ) //if element has a callback
					this->_mouseCallback(this);
				if (_down) this->_imageE->darken();
				else this->_imageE->lighten();
			}
		}

	private:
	    bool _down;
};
#endif
