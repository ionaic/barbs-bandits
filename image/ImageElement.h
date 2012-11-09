#ifndef _IMAGE_ELEMENT_H_
#define _IMAGE_ELEMENT_H_
/*! \file This file contains the ImageElement class. */
#include <iostream>
#include "Pixel.h"
#include "Image.h"
#include "Element.h"


/*! \brief An element which simply contains an image and has children.  
 *
 * Its main purpose  is to provide constructors and to override 
 * Element::clearResult() to fill the background with the contained 
 * image instead of a plain color.
 */
class ImageElement : public Element {
    friend class ProgressBar;
    friend class SliderBar;
    public:
        // public constructors
        /*! \brief Default constructor. */
        /*! \brief Constructor to create an element out of the given image. */
        ImageElement(Image &img) : 
            Element(0, 0, img.width(), img.height()) { this->_img = new Image(img); }
        /*! \brief Constructor to create an image element at a location. */
        ImageElement(unsigned int x, unsigned int y, const char *fname): Element(x,y, 0, 0) {
            this->_img = new Image(fname);
            _width = _img->width();
            _height = _img->height();
            delete _result;
            delete _clrImg;
            _result = new Image(this->_width, this->_height);
            _clrImg = new Image(this->_width, this->_height);
            cout << _width << "  " << _height << endl;
        }
        /*! \brief Constructor to create an image element at (x,y) with dimensions
         * (width, height).
         */
        ImageElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height) : 
            Element(x, y, width, height) { this->_img = new Image(width, height); }
        /* \brief calls the darken function of image */
        void darken() { _img->darken(); setDirty(true);}
        /* \brief calls the darken function of image */
        void lighten() { _img->lighten(); setDirty(true);}
        /*! \brief Constructor to create an image element at (x, y) in the parent
         * with dimensions (width, height) and the specified content image.
         */
        ImageElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height, Image &img) : 
            Element(x, y, width, height) { this->_img = new Image(img); }
        /*! \brief Destructor.  Deletes the content image. */
        ~ImageElement() { delete this->_img; }
        /*! \brief Overrides Element::clearResult() to clear background to the
         * content image instead of a solid color.
         */
        void clearResult(unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
            Element::clearResult(x, y, width, height);
            this->_img->blit(*(this->_result),  x, y, x, y, width, height);
        }

    private:
        Image* _img;
};
#endif
