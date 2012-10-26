#include <string>
#include "Image.h"
#include "Text.h"
#include "Button.h"

using namespace std;

class ToggleButton: public Button {
	public:
        ToggleButton() : Button() { this->_on = false; }
        ToggleButton(int x, int y) : Button(x, y) { this->on = false; }
        ToggleButton(int x, int y, int w, int h) : 
            Button(x, y, w, h) { this->on = false; }
        ToggleButton(int x, int y, int w, int h, 
            string content, int size, Image i) : Button(x, y, w, h) {
            this->_on = false;
            Element::addChild(i);
            Element::addChild(new Text(width,height,size,content));
        }
        ~ToggleButton() { Button::~Button(); }

	private:
	    bool _on;
};
