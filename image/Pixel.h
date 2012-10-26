#ifndef _PIXEL_H_
#define _PIXEL_H_

#include <iostream>

class Pixel {
public:
	Pixel();
	Pixel(int R, int G, int B);
	Pixel(int R, int G, int B, int A);
	void setRGB(int R, int G, int B);
	void setRGBA(int R, int G, int B, int A);
	int getR() const;
	int getG() const;
	int getB() const;
	int getA() const;
	friend std::ostream& operator<< (std::ostream &out, const Pixel &p);
private:
	unsigned char _r, _g, _b, _a;
};
#endif
