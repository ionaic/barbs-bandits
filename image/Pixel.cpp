#include "Pixel.h"
#include <cstdlib>

Pixel::Pixel() {}
Pixel::Pixel(int R, int G, int B) {
	_r = R; _g = G; _b = B; _a = 255;
}
Pixel::Pixel(int R, int G, int B, int A) {
	_r = R; _g = G; _b = B; _a = A;
}

Pixel::Pixel(Pixel &p)
{
	this->_r = p.getR();
	this->_g = p.getG();
	this->_b = p.getB();
	this->_a = p.getA();
}

void Pixel::setRGB(int R, int G, int B) {
	setRGBA(R, G, B, getA());
}
void Pixel::setRGBA(int R, int G, int B, int A) {
	_r = std::max(std::min(255, R), 0);
	_g = std::max(std::min(255, G), 0);
	_b = std::max(std::min(255, B), 0);
	_a = std::max(std::min(255, A), 0);
}
void Pixel::setA(int A) {
    _a = std::max(std::min(255, A), 0);
}
int Pixel::getR() const {
	return _r;
}
int Pixel::getG() const {
	return _g;
}
int Pixel::getB() const {
	return _b;
}
int Pixel::getA() const {
	return _a;
}
std::ostream& operator<< (std::ostream &out, const Pixel &p) {
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
