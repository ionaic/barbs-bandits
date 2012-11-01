#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <iostream>
#include "Pixel.h"
#include "Image.h"

class Image {
public:
	Image();
	Image(unsigned int width, unsigned int height);
	Image(unsigned int width, unsigned int height, const Pixel &p);
	Image(unsigned int width, unsigned int height, unsigned char* data);
    Image(Image &img);
	~Image();
	unsigned int width() const;
	unsigned int height() const;
	void set(unsigned int x, unsigned int y, const Pixel &color);
	void set(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height, const Pixel &color);
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
