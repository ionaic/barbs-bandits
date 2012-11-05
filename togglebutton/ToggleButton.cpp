#include <string>
#include "../image/ImageElement.h"
#include "../text/TextElement.h"
#include "../text/Text.h"
#include "../button/Button.h"
#include "ToggleButton.h"

using namespace std;

/*! Default constructor creates an empty unclicked togglebutton.*/
ToggleButton::ToggleButton() : Button() {
	this->_down = false;
}

/*! Constructor creates an unclicked togglebutton at position x,y. */
ToggleButton::ToggleButton(int x, int y) : Button(x, y) {
	this->_down = false;
}

/*! Constructor creates an unclicked togglebutton at position x,y with width and height. */
ToggleButton::ToggleButton(int x, int y, int w, int h) : Button(x, y, w, h) {
	this->_down = false;
}

/*! Constructor creates an unclicked togglebutton at position x,y with width, height and text. */
ToggleButton::ToggleButton(int x, int y, int w, int h, string txt) : Button(x, y, w, h, txt) {
	cout << "creating tbutton" << endl;
	this->_down = false;
}

/*! Constructor creates an unclicked togglebutton at position x,y with width, height, text, font size and a background image. */
ToggleButton::ToggleButton(int x, int y, int w, int h, 
		string content, int size, ImageElement* i) : Button(x, y, w, h, i) {
	this->_down = false;
}

/*! mouseInput overload for ToggleButton for animation */
void ToggleButton::mouseInput(int x, int y) {
	if ( x < 0 || y < 0) return;
	bool inside = (this->_width >= x && this->_height >= y);

	if (inside) { //if inside button
		cout << "Inside tbutton" << endl;
		_down = !_down;
		if (_down) this->_imageE->darken();
		else this->_imageE->lighten();
		if (0 != _mouseCallback ) //if element has a callback
			this->_mouseCallback(this);
	}
}
