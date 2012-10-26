#pragma once

#include <iostream>
#include "Pixel.h"
#include "Image.h"
#include "Element.h"

class ImageElement : public Element {
    public:
        // public constructors
        ImageElement() : Element() {}
        ImageElement(Image* img) : Element() { this->_img = img; }
        ImageElement(unsigned int x, unsigned int y) : Element(x, y, 0, 0) {}
        ImageElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height) : 
            Element(x,y,width,height) {}
        ImageElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height, Image *img) : Element(x, y, width, height) {
            this->_img = img;
        }
        ~ImageElement() { 
            delete _img;
        }
        virtual void clearResult() {
            this->_img->blit(*(this->_result),  0U, 0U, 0U, 0U, this->_width, this->_height);
        }
    private:
        Image* _img;
};
