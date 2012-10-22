#pragma once

#include <string>
#include "Image.h"
#include "Text.h"
#include "Element.h"

using namespace std;

class Button : public Element {
	public:
        Button() : Element() {}
        Button(int x, int y, int width, int height) : 
            Element(x, y, width, height) {}
		Button(int x, int y, int w, int h, string content, int size, Image* image) :
            Element(x, y, w, h) {
            Element::addChild(image);
        }
		~Button() { Element::~Element(); }
};
