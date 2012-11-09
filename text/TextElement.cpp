#include <string>
#include "Text.h"
#include "TextElement.h"
#include "../image/Image.h"
#include "../element/Element.h"

using namespace std;


/*! Constructor with x,y position, width and height sets font size to 1 and an empty string */
TextElement::TextElement(unsigned int x, unsigned int y,
        unsigned int width, unsigned int height): Element(x, y, width, height) {
    this->_text = new Text(width, height, 1, "");
}

/*! Constructor sets all variables and dynamically creates a Text object */
TextElement::TextElement(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height, int size, string txt) : Element(x, y, width, height) {
	this->_text = new Text(width, height, size, txt);
}

/*! Destructor deletes dynamically allocated variables if needed */
TextElement::~TextElement() {
	if (_text) {
		delete _text;
	}
}

/*! Updates the value of the text which renders the text */
void TextElement::setText(string txt) {
	this->_text->setText(txt);
	this->setDirty(true);
}

/*! Clears the rendered image we have stored */
void TextElement::clearResult(unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
	Image* _temp = this->_text->getImage();
	Element::clearResult();
	if (_temp) _temp->blit(*(this->_result), x, y, x, y,
			width, height);
	else cout << "ERROR in TextElement during clearResult blit." <<
		" No image available. ID:" << this->getId() << endl;
}
