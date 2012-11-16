#include "NumericCounter.h"
#include "../text/TextElement.h"
#include <sstream>

/*!Constructor that can be passed a value, xy coords, and width / height. */
NumericCounter::NumericCounter(int x, int y, int width,
        int height, int value) : AbstractCounter(x, y, width, height, value) {
    string s = static_cast<ostringstream*>( &(ostringstream()
            << value) )->str();
    _textE = new TextElement(0, 0, _width, _height, 0, s);
	Element::addChild(_textE);
}

/*! default destructor */
NumericCounter::~NumericCounter(){
	delete _textE;
}

/*!Override AbstractCounter's setValue.  Takes an integer as the argument */
bool NumericCounter::setValue(int value){
	_value = value;
	_update();
	return true;
}

/*!++ operator to increment the counter */
NumericCounter &NumericCounter::operator++(int) {
    _value++;
    _update();
    return *this;
}

/*!-- operator to decrement the counter */
NumericCounter &NumericCounter::operator--(int) {
    _value--;
    _update();
    return *this;
}

//forces the element to update
void NumericCounter::_update() {
    string s = static_cast<ostringstream*>( &(ostringstream()
            << _value) )->str();
    _textE->setText(s);
}
