#ifndef _TEXT_ELEMENT_H_
#define _TEXT_ELEMENT_H_

#include <string>
#include "Text.h"
#include "Image.h"
#include "Element.h"

class TextElement : public Element {
    public:
        TextElement() : Element() { this->_text = new Text(0, 0, 0, ""); }
        TextElement(unsigned int x, unsigned int y) : Element(x, y) { this->_text = new Text(0, 0, 0, ""); }
        TextElement(unsigned int x, unsigned int y, Text &txt) { this->_text = new Text(txt); }
        TextElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height) : Element(x, y, width, height) { this->_text = new Text(0, 0, 0, ""); }
        TextElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height, Text * txt) { this->_text = new Text(0, 0, 0, ""); }
        ~TextElement() { delete _text; }
        void setText(string text) {
            this->_text = new Text(this->_width, this->_height, 10, text);
        }
        void setText(Text& text) {
            this->_text = new Text(text);
        }

    private: 
        Text* _text;
};
#endif
