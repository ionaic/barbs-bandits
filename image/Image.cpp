#include "Image.h"
#include <algorithm>

inline unsigned int Image::_getCoord(unsigned int x, unsigned int y) const {
	return y*_width+ x;
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
	for (int i=0; i < height * width; ++i)
		_pixels[i].setRGBA(0,0,0,0); //initialize to pure alpha
}
/*!
\brief Creates an image of size (width,height) and initializes it to p.

\param width Defines the width of the image in pixels.
\param height Defines the height of the image in pixels.
\param p Defines the default color to set all of the pixels in the image to.

\return A new Image class.
*/
Image::Image(unsigned int width, unsigned int height, const Pixel &p) {
	_width = width;
	_height =height;
	_pixels = new Pixel[width*height];
	for (unsigned int i=0; i<width*height; ++i) {
		_pixels[i] = p;
	}
}

/*!
\brief Copy constructor.

\param img The Image to copy into this one.

\return A new Image class.
*/
Image::Image(Image &img) {
    _width = img._width;
    _height = img._height;
    _pixels = new Pixel[_width * _height];
    Pixel* pix = img.getPixels();
    for (unsigned int i = 0; i < _width * _height; i++) {
        _pixels[i] = pix[i];
    }
}
/*!
\brief Creates an image of size (width,height) and initializes it to data.

\param width Defines the width of the image in pixels.
\param height Defines the height of the image in pixels.
\param data Raw data to copy into the image.  Each pixel should start at
relative address \f$(y*width+x)*4\f$ and have 1 byte for the channels RGBA
(in that order).

\return A new Image class.
*/
Image::Image(unsigned int width, unsigned int height, unsigned char *data) {
	_width = width;
	_height =height;
	_pixels = new Pixel[width*height];
	if (!data)
		std::cout << "Error reading data in Image constructor" << std::endl;
	else {
		for (unsigned int i=0; i<width*height*4; i+=4) {
			_pixels[i/4].setRGBA(data[i], data[i+1], data[i+2], data[i+3]);
		}
	}
}
/*! \brief destructor */
Image::~Image() {
	if (_pixels!=0) {
		delete[] _pixels;
		_pixels = 0;
	}
}
/*! \brief Retrieve the width. */
unsigned int Image::width() const {
	return _width;
}
/*! \brief Retrieve the height. */
unsigned int Image::height() const {
	return _height;
}
/*!
\brief Sets the color of a particular pixel.

\param x Defines the x coordinate of the pixel.
\param y Defines the y coordinate of the pixel.
\param color Defines the default color to set the pixel to.

\return void
*/
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
/*!
\brief Sets the color of a pixel region.

\param x Defines the left of the region.
\param y Defines the top of the region.
\param width Defines the width of the region.
\param height Defines the height of the region.
\param color Defines the default color to set the pixels to.

\return void
*/
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
Pixel ERRORPIXEL;
/*!
\brief Gets the value of a pixel.

\param x The x coordinate of the desired pixel.
\param y The y coordinate of the desired pixel.

\return A constant reference to the value.
*/
const Pixel &Image::get(unsigned int x, unsigned int y) const {
	if (x>=_width || y>=_height) {
		if (!_pixels) {
			std::cout << "ERROR: Tried to get a pixel" <<
				"in an uninitialized image!" << std::endl;
		} else {
			std::cout << "ERROR: Pixel coordinate is out of bounds\n" <<
				"{XY: " << x << ", " << y << "}" << std::endl; 
		}
		return ERRORPIXEL;
	}
	return _pixels[_getCoord(x,y)];
}
/*!
\brief Copy a region of this Image to another.

\param dest The image to copy to.
\param xSource Defines the left side of the source region.
\param ySource Defines the top of the source region.
\param xDest Defines the left side of the destination region.
\param yDest Defines the top of the destination region.
\param width Defines the width of the regions.
\param height Defines the height of the regions.

\return void
*/
void Image::blit(Image &dest, unsigned int xSource, unsigned int ySource,
                        unsigned int xDest,   unsigned int yDest,
                        unsigned int width,   unsigned int height) const{
	if (!_pixels || !width || !height) {
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
				if (_pixels[_getCoord(xSource+x, ySource+y)].getA()>127) {
					dest._pixels[dest._getCoord(xDest+x,yDest+y)] =
						_pixels[_getCoord(xSource+x,ySource+y)];
				}
			}
		}
	}
}

/*!  \brief lighten the entire image */
void Image::lighten() {
	std::cout << "before l: " << _pixels[_width * _height - 1].getR() << std::endl;
	for (unsigned int i = 0; i < _width * _height; ++i) {
		int _dR = _pixels[i].getR() + 50;
		int _dG = _pixels[i].getG() + 50;
		int _dB = _pixels[i].getB() + 50;
		_pixels[i].setRGB(_dR,  _dG,  _dB);
	}
	std::cout << "after l: " << _pixels[_width * _height - 1].getR() << std::endl;
}

/*! \brief Darken the entire image */
void Image::darken() {
	std::cout << "before D: " << _pixels[_width * _height - 1].getR() << std::endl;
	for (unsigned int i = 0; i < _width * _height; ++i) {
		int _dR = _pixels[i].getR() - 50;
		int _dG = _pixels[i].getG() - 50;
		int _dB = _pixels[i].getB() - 50;
		_pixels[i].setRGB(_dR,  _dG,  _dB);
	}
	std::cout << "after d: " << _pixels[_width * _height - 1].getR() << std::endl;
}

/*!
\brief Write an Image to an ostream.

\param out The output stream.
\param img The Image to write to the ostream.

\return ostream Passes out the same ostream

Outputs the dimensions and all of the pixel data for the image.

*/
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
