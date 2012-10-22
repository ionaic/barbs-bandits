#include "Image.h"
inline unsigned int Image::_getCoord(unsigned int x, unsigned int y) const {
	return x*_height + y;
}
Image::Image() {
	_pixels = 0;
	_width = 0;
	_height = 0;
}
Image::Image(unsigned int width, unsigned int height) {
	_width = width;
	_height = height;
	_pixels = new Pixel[width*height];
}
Image::Image(unsigned int width, unsigned int height, const Pixel &p) {
	_width = width;
	_height =height;
	_pixels = new Pixel[width*height];
	for (unsigned int i=0; i<width*height; ++i) {
		_pixels[i] = p;
	}
}
Image::~Image() {
	if (_pixels) {
		delete[] _pixels;
	}
}
unsigned int Image::width() const {
	return _width;
}
unsigned int Image::height() const {
	return _height;
}
void Image::set(unsigned int x, unsigned int y, const Pixel &color) {
	if (x>=_width || y>=_height) {
		if (!_pixels) {
			std::cout << "ERROR: Tried to set a pixel" <<
				"in an uninitialized image!" << std::endl;
		} else {
			std::cout << "ERROR: Pixel coordinate is out of bounds\n" <<
				"{XY: " << x << ", " << y << "}" << std::endl; 
		}
		return;
	}
	unsigned int coord = _getCoord(x,y);
	_pixels[coord] = color;
}
void Image::set(unsigned int x, unsigned int y, unsigned int width,
				unsigned int height, const Pixel &color) {
	if (x+width>_width || y+width>_height) {
		if (!_pixels) {
			std::cout << "ERROR: Tried to set a pixel" <<
				"in an uninitialized image!" << std::endl;
		} else {
			std::cout << "ERROR: Pixel region is out of bounds\n" <<
				"  Top Left {XY: " << x << ", " << y << "}" << 
				"Dimensions {WH: " << width << ", " << height << "}" <<
				std::endl;
		}
		return;
	}
	for (unsigned int px = x; px<x+width; ++px) {
		for (unsigned int py=y; py<x+height; ++py) {
			unsigned int coord = _getCoord(px,py);
			_pixels[coord] = color;
		}
	}
}
const Pixel &Image::get(unsigned int x, unsigned int y) const {
	if (x>=_width || y>=_height) {
		if (!_pixels) {
			std::cout << "ERROR: Tried to get a pixel" <<
				"in an uninitialized image!" << std::endl;
		} else {
			std::cout << "ERROR: Pixel coordinate is out of bounds\n" <<
				"{XY: " << x << ", " << y << "}" << std::endl; 
		}
		return Pixel();
	}
	return _pixels[_getCoord(x,y)];
}
void Image::blit(Image &dest, unsigned int xSource, unsigned int ySource,
                        unsigned int xDest,   unsigned int yDest,
                        unsigned int width,   unsigned int height) const{
	if (!_pixels) {
		std::cout << "ERROR: Tried to blit" <<
			"in an uninitialized image!" << std::endl;
	} else if (!dest._pixels) {
		std::cout << "ERROR: Tried to blit"
			<< "to an uninitialized image!" << std::endl;
	} else if (xSource+width>_width || ySource+height>_height) {
		std::cout << "ERROR: Pixel region is out of bounds in Source\n" <<
			"   Top Left {XY: " << xSource << ", " << ySource << "}\n" <<
			" Dimensions {WH: " << width << ", " << height << "}" <<
			"Source Size {WH: " << _width << ", " << _height << "}" <<
			std::endl;
	} else if (xDest+width>dest._width || yDest+height>dest._height) {
		std::cout << "ERROR: Pixel region is out of bounds in Dest\n" <<
			"  Top Left {XY: " << xDest << ", " << yDest << "}\n" <<
			"Dimensions {WH: " << width << ", " << height << "}\n" <<
			" Dest Size {WH: " << dest._width << ", "<<dest._height<<"}"<<
			std::endl;
	} else {
		for (unsigned int x = 0; x<width; ++x) {
			for (unsigned int y = 0; y<height; ++y) {
				dest._pixels[dest._getCoord(xDest+x,yDest+y)] =
					_pixels[_getCoord(xSource+x, ySource+y)];
			}
		}
	}
}
std::ostream &operator<<(std::ostream &out, const Image &img) {
	out << "Image Dimensions {WH: " << img.width() << ", "
		<< img.height() << "}\n";
	for (unsigned int y=0; y<img.height(); ++y) {
		for (unsigned int x=0; x<img.width(); ++x) {
			out << img.get(x,y);
		}
		out << "\n";
	}
	return out;
}
