#ifndef _PIXEL_H_
#define _PIXEL_H_

#include <iostream>
/*! \brief Stores the raw pixel data for one Pixel

Currently only supports R8G8B8A8 Pixel data.*/
class Pixel {
public:
	/*! \brief Default Constructor. Leaves memory uninitialized */
	Pixel();
	/*! \brief Use the RGB Parameters for the Pixel. Set A to 255. */
	Pixel(int R, int G, int B);
	/*! \brief Use the RGBA parameters for the Pixel. */
	Pixel(int R, int G, int B, int A);
	/*! \brief Copy constructor */
	Pixel(Pixel &p);
	/*! \brief Use the RGB Parameters for the Pixel. Set A to 255. */
	void setRGB(int R, int G, int B);
	/*! \brief Use the RGBA parameters for the Pixel. */
	void setRGBA(int R, int G, int B, int A);
	/* \brief Set the R parameter of the Pixel. */
	int getR() const;
	/* \brief Set the G parameter of the Pixel. */
	int getG() const;
	/* \brief Set the B parameter of the Pixel. */
	int getB() const;
	/* \brief Set the A parameter of the Pixel. */
	int getA() const;
	/* \brief Output the RGBA values of a Pixel. */
	friend std::ostream& operator<< (std::ostream &out, const Pixel &p);
private:
	unsigned char _r, _g, _b, _a;
};
#endif
