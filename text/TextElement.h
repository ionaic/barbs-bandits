#ifndef _TEXT_ELEMENT_H_
#define _TEXT_ELEMENT_H_

#include <string>
#include "Text.h"
#include "../image/Image.h"
#include "../element/Element.h"

class TextElement : public Element {
    public:
        TextElement(unsigned int x, unsigned int y);

        TextElement(unsigned int x, unsigned int y, unsigned int width,
        		unsigned int height);

        TextElement(unsigned int x, unsigned int y, unsigned int width,
        		unsigned int height, int size, string txt);

        ~TextElement();
        void setText(string txt);

        void clearResult();

    private: 
        Text* _text;
};
#endif
