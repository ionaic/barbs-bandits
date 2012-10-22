#include <string>
#include "../image/Image.h"
#include "../text/Text.h"
#include "Button.h"

using namespace std;

Button::Button(string content, int w, int h, int size, Image i) {
	width = w;
	height = h;
	image = i;
	text = new Text(width,height,size,content);
}

Button::~Button() {
	if (text) 
		delete text;
}
