/*! \file
Contains everything needed to use the Image Class.
*/
#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <iostream>
#include "Pixel.h"
/*! \brief Contains an image and allows for basic manipulation.

Currently, only R8G8B8A8 images are supported. Data is stored raw to allow for
easy access to OpenGL and DirectX.
*/
class Image {
public:
	Image(); /*!< Creates a blank Image of size (0,0) */
	/*! \brief Creates Image of size (width,height) with uninitialized Pixel data*/
	Image(unsigned int width, unsigned int height);
	Image(unsigned int width, unsigned int height, const Pixel &p);
	Image(unsigned int width, unsigned int height, unsigned char* data);
    Image(Image &img);
	Image(const char *);
    ~Image();
	unsigned int width() const;
	unsigned int height() const;
	void set(unsigned int x, unsigned int y, const Pixel &color);
	void set(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height, const Pixel &color);
	void set(unsigned int x, unsigned int y, unsigned int width,
	                unsigned int height, int alpha);
	const Pixel &get(unsigned int x, unsigned int y) const;
	Pixel* getPixels() {return _pixels;}
	void blit(Image &dest, unsigned int xSource, unsigned int ySource,
                           unsigned int xDest,   unsigned int yDest,
                           unsigned int width,   unsigned int height) const;
	friend std::ostream &operator<<(std::ostream &out, const Image &img);
	void lighten();
	void darken();
private:
	Pixel *_pixels;
	unsigned int _width, _height;
	inline unsigned int _getCoord(unsigned int x, unsigned int y) const;
};
#endif
