#ifndef _TEXT_ELEMENT_H_
#define _TEXT_ELEMENT_H_

#include <string>
#include "Text.h"
#include "Image.h"
#include "Element.h"

class TextElement : public Element {
    public:
        //TextElement() : Element() { this->_text = new Text(); }
        TextElement(unsigned int x, unsigned int y) {
        	TextElement(x, y, 0, 0 ,0, "");
        }

        //TODO: CREATING A TEXT ELEMENT WITH 0 font size and no text causes a seg fault in text (below)
        TextElement(unsigned int x, unsigned int y, unsigned int width,
        		unsigned int height) { TextElement(x, y, width, height , 0, ""); }

        //TextElement(unsigned int x, unsigned int y, Text &txt) { this->_text = new Text(txt); }
        TextElement(unsigned int x, unsigned int y, unsigned int width,
        		unsigned int height, int size, string txt) : Element(x, y, width, height) {
        	this->_text = new Text(width, height, size, txt);
        	cout << "creating text element with text: " << _text->getText() << endl;

        }
        //~TextElement() { delete _text; }
        void setText(string txt) {
            this->_text->setText(txt);
        }
        void clearResult() {
        	Image* _temp = this->_text->getImage();
        	cout << _text->getText() << endl;
        	if (_temp) _temp->blit(*(this->_result), 0U, 0U, 0U, 0U,
        			this->_width, this->_height);
        	else cout << "ERROR in TextElement during clearResult blit." <<
        			" No image available. (text too long?)  ID:" << this->_id << endl;
        }

    private: 
        Text* _text;
};
#endif
