#include <iostream>
#include "Image.h"
using namespace std;

int main() {
	Image img(3,4,Pixel(0,0,0));
	Image img2(2,2,Pixel(255,0,0));
	cout << img;
	cout << img2;
	img2.blit(img,0,0,1,0,2,1);
	cout << img;
	cout << sizeof(img.get(0,0)) << endl;
	img2.set(0,0,2,2,Pixel(0,255,0));
	cout << img2;
	system("pause");
	return 0;
}
