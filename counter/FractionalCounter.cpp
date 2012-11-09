#include <string>
#include <sstream>
#include "../image/Image.h"
#include "../text/Text.h"
#include "../element/Element.h"
#include "../image/ImageElement.h"
#include "../text/TextElement.h"
#include "FractionalCounter.h"

using namespace std;

FractionalCounter::FractionalCounter(int x, int y, int width, int height, int value, int max) : BoundedCounter(x,y,width,height,value,max) {
	string s1 = static_cast<ostringstream*>( &(ostringstream() << value) )->str();
	string s2 = static_cast<ostringstream*>( &(ostringstream() << _max) )->str();
	string result = s1 + "/" + s2;
	_textE = new TextElement(0, 0, width, height, 0, result);
	addChild(_textE);
	render();
}

FractionalCounter::~FractionalCounter() {
	delete _textE;
}

FractionalCounter &FractionalCounter::operator++(int) {
	if(setValue(getValue()+1)) { //Returns false on failure
		_update();
	}
	return * this;
}

FractionalCounter &FractionalCounter::operator--(int) {
	if(setValue(getValue()-1)) { //Returns false on failure
		_update();
	}
	return * this;
}

void FractionalCounter::_update() {
	string s1 = static_cast<ostringstream*>( &(ostringstream() << getValue()) )->str();
	string s2 = static_cast<ostringstream*>( &(ostringstream() << _max) )->str();
	string result = s1 + "/" + s2;
	_textE->setText(result);
}
