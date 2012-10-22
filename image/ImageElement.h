#pragma once

#include <iostream>
#include "Pixel.h"
#include "Image.h"
#include "Element.h"

class ImageElement : public Element {
    public:
        // public constructors
        ImageElement() : Element() {}
        ImageElement(unsigned int x, unsigned int y) : Element(x, y, 0, 0) {}
        ImageElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height) : 
            Element(x,y,width,height) {}
        ImageElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height, Image *_img) : 
        ~ImageElement() { 
            delete _img;
            Element::~Element(); 
        }
        virtual clearResult() {
            this->_img->blit(this->_result,  0, 0, 0, 0, this->width, this->height);
        }
    private:
        Image* _img;
};
