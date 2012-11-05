#include "NumericCounter.h"
#include "../text/TextElement.h"
#include <sstream>

NumericCounter::NumericCounter(){
	NumericCounter(0, 0, 0, 0, 0);
}

NumericCounter::NumericCounter(int x, int y, int width,
        int height, int value) : AbstractCounter(x, y, width, height, value) {
    string s = static_cast<ostringstream*>( &(ostringstream() << value) )->str();
    _textE = new TextElement(0, 0, _width, _height, 14, s);
	Element::addChild(_textE);
}

NumericCounter::~NumericCounter(){
	delete _textE;
}

bool NumericCounter::setValue(int value){
	_value = value;
	string s = static_cast<ostringstream*>( &(ostringstream() << value) )->str();
	_textE->setText(s);
	setDirty(true); //update the result image
	return true;
}