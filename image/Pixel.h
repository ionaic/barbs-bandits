#pragma once
#include <iostream>

class Pixel {
private:
	unsigned char _r, _g, _b, _a;
public:
	Pixel() {}
	Pixel(int R, int G, int B) {
		_r = R; _g = G; _b = B; _a = 255;
	}
	Pixel(int R, int G, int B, int A) {
		_r = R; _g = G; _b = B; _a = A;
	}
	void setRGB(int R, int G, int B) {
		_r = R; _g = G; _b = B; _a = 255;
	}
	void setRGBA(int R, int G, int B, int A) {
		_r = R; _g = G; _b = B; _a = A;
	}
	int getR() const {
		return _r;
	}
	int getG() const {
		return _g;
	}
	int getB() const {
		return _b;
	}
	int getA() const {
		return _a;
	}
	friend std::ostream& operator<< (std::ostream &out, const Pixel &p) {
		out << "{RGBA: ";
		if (p._r<10) out << " ";
		if (p._r<100) out << " ";
		out << (int)p._r << ", ";
		if (p._g<10) out << " ";
		if (p._g<100) out << " ";
		out << (int)p._g << ", ";
		if (p._b<10) out << " ";
		if (p._b<100) out << " ";
		out << (int)p._b << ", ";
		if (p._a<10) out << " ";
		if (p._a<100) out << " ";
		out << (int)p._a << "}";
		return out;
	}
};
