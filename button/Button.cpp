#pragma once

#include <string>
#include "Image.h"
#include "Text.h"
#include "Button.h"
#include "Element.h"

using namespace std;

Button::Button() {
    Element::Element();
}

Button::Button(int x, int y, string content, int w, int h, int size, Image i) {
    Element::Element(x, y, w, h);
	Element::addChild(new Text(width,height,size,content));
}

Button::~Button() {
    Element::~Element();
}
