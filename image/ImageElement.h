#ifndef _IMAGE_ELEMENT_H_
#define _IMAGE_ELEMENT_H_

#include <iostream>
#include "Pixel.h"
#include "Image.h"
#include "../element/Element.h"

class ImageElement : public Element {
    public:
        // public constructors
        ImageElement() : Element() {}
        ImageElement(Image &img) : Element() { this->_img = new Image(img); }
        ImageElement(unsigned int x, unsigned int y) : Element(x, y, 0, 0) {
        	ImageElement(x, y, 0, 0);
        }
        ImageElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height) : 
            Element(x, y, width, height) { this->_img = new Image(width, height); }
        ImageElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height, Image &img) : Element(x, y, width, height) {
            this->_img = new Image(img);
        }
        void clearResult() { 
            this->_img->blit(*(this->_result),  0U, 0U, 0U, 0U, this->_width, this->_height);
        }
    private:
        Image* _img;
};
#endif
