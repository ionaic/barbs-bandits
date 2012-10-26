#pragma once

#include <string>
#include "Image.h"
#include "Text.h"
#include "Element.h"
#include "ImageElement.h"
#include "TextElement.h"

using namespace std;

class Button : public Element {
	public:
        Button() : Element() {}
        Button(unsigned int x, unsigned int y) : Element(x, y) {}
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height) : Element(x, y, width, height) {}
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height, ImageElement* img) : Element(x, y, width, height) { Element::addChild(img); }
		//Button(unsigned int x, unsigned int y, unsigned int w, unsigned int h, TextElement* content, unsigned int size, ImageElement* image) : Element(x, y, w, h) {
        //    Element::addChild(image);
        //}
        void setText(TextElement* text) { Element::addChild(text); }
        void setBgImg(ImageElement* img) { Element::addChild(img); }
		virtual ~Button() {}
};
