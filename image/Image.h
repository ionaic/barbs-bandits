#pragma once
#include <iostream>
#include "Pixel.h"
#include "Image.h"

class Image {
public:
	Image();
	Image(unsigned int width, unsigned int height);
	Image(unsigned int width, unsigned int height, const Pixel &p);
	Image(unsigned int width, unsigned int height, unsigned char* p );
	~Image();
	unsigned int width() const;
	unsigned int height() const;
	void set(unsigned int x, unsigned int y, const Pixel &color);
	void set(unsigned int x, unsigned int y, unsigned int width,
		unsigned int height, const Pixel &color);
	const Pixel &get(unsigned int x, unsigned int y) const;
	void blit(Image &dest, unsigned int xSource, unsigned int ySource,
                           unsigned int xDest,   unsigned int yDest,
                           unsigned int width,   unsigned int height) const;
	friend std::ostream &operator<<(std::ostream &out, const Image &img);
private:
	Pixel *_pixels;
	unsigned int _width, _height;
	inline unsigned int _getCoord(unsigned int x, unsigned int y) const;
};
