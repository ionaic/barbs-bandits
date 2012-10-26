#pragma once

#include <string>
#include "Text.h"
#include "Image.h"
#include "Element.h"

class TextElement : public Element {
    public:
        TextElement() : Element() {}
        TextElement(unsigned int x, unsigned int y) : Element(x, y) {}
        TextElement(unsigned int x, unsigned int y, Text* txt) { this->_text = txt; }
        TextElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height) : Element(x, y, width, height) {}
        TextElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height, Text * txt) { }
        void setText(string text) {
            this->_text = new Text(this->_width, this->_height, 10, text);
        }
        void setText(Text* text) {
            this->_text = text;
        }

    private: 
        Text* _text;
};
