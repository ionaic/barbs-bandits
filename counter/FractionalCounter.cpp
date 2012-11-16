#include <string>
#include <sstream>
#include "../image/Image.h"
#include "../text/Text.h"
#include "../element/Element.h"
#include "../image/ImageElement.h"
#include "../text/TextElement.h"
#include "FractionalCounter.h"

using namespace std;

/*!Constructor with starting values.  Allows the user to set the x and y coordinates of the Element as well as the width and height.  Also sets the counter's maximum value */
FractionalCounter::FractionalCounter(int x, int y, int width, int height,
        int value, int max) : BoundedCounter(x,y,width,height,value,max) {
	string s1 = static_cast<ostringstream*>( &(ostringstream()
	        << value) )->str();
	string s2 = static_cast<ostringstream*>( &(ostringstream()
	        << _max) )->str();
	string result = s1 + "/" + s2;
	_textE = new TextElement(0, 0, width, height, 0, result);
	addChild(_textE);
	render();
}

/*!default destructor */
FractionalCounter::~FractionalCounter() {
	delete _textE;
}

/*!++ operator to increment the counter */
FractionalCounter &FractionalCounter::operator++(int) {
	if(setValue(getValue()+1)) { //Returns false on failure
		_update();
	}
	return * this;
}

/*!-- operator to decrement the counter */
FractionalCounter &FractionalCounter::operator--(int) {
	if(setValue(getValue()-1)) { //Returns false on failure
		_update();
	}
	return * this;
}

//forces an update on the element
void FractionalCounter::_update() {
	string s1 = static_cast<ostringstream*>( &(ostringstream()
	        << getValue()) )->str();
	string s2 = static_cast<ostringstream*>( &(ostringstream() << _max) )->str();
	string result = s1 + "/" + s2;
	_textE->setText(result);
}
