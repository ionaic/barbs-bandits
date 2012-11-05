#include <string>
#include "../image/Image.h"
#include "../text/Text.h"
#include "../element/Element.h"
#include "../image/ImageElement.h"
#include "../text/TextElement.h"
#include "NumericCounter.h"

NumericCounter::NumericCounter(){
	NumericCounter(0);
};

NumericCounter::NumericCounter(int value) : AbstractCounter(value) {
	_imageE = new ImageElement(_width, _height);
	addChild(_imageE);
	_textE = new TextElement(_width, _height, (string) value);
	addchild(_textE);
};

NumericCounter::~NumericCounter(){
	delete _imageE;
	delete _textE;
};

bool NumericCounter::setValue(int value){
	_value = value;
	render(); //update the result image
}
