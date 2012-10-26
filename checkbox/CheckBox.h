#ifndef _CHECKBOX_H_
#define _CHECKBOX_H_

#include "Element.h"
#include "Text.h"
#include "Image.h"
#include "ImageElement.h"
#include "TextElement.h"

using namespace std;

class CheckBox : public Element {
    public:
        CheckBox() : Element() {}
        CheckBox(unsigned int x, unsigned int y) : Element(x, y) {}
};
#endif
