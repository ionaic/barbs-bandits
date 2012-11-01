#include <string>
#include "Text.h"
#include "TextElement.h"
#include "../image/Image.h"
#include "../element/Element.h"

using namespace std;

//Constructor with just x,y position sets sizes to zero and font size to 1 and uses an empty string
TextElement::TextElement(unsigned int x, unsigned int y) {
	TextElement(x, y, 0, 0 , 1, "");
}

//Constructor with x,y position, width and height sets font size to 1 and an empty string
TextElement::TextElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
	TextElement(x, y, width, height , 1, "");
}

//Constructor sets all variables and dynamically creates a Text object
TextElement::TextElement(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height, int size, string txt) : Element(x, y, width, height) {
	this->_text = new Text(width, height, size, txt);
	cout << "creating text element with text: " << _text->getText() << endl;
}

//Destructor deletes _text if it exists
TextElement::~TextElement() {
	if (_text) {
		delete _text;
	}
}

//Updates the value of the text which renders the text
void TextElement::setText(string txt) {
	this->_text->setText(txt);
}

//Clears the rendered image we have stored
void TextElement::clearResult() {
	Image* _temp = this->_text->getImage();
	if (_temp) _temp->blit(*(this->_result), 0U, 0U, 0U, 0U,
			this->_width, this->_height);
	else cout << "ERROR in TextElement during clearResult blit." <<
		" No image available. ID:" << this->getId() << endl;
}
