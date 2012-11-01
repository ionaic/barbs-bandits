#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <string>
#include "../image/Image.h"
#include "../text/Text.h"
#include "../element/Element.h"
#include "../image/ImageElement.h"
#include "../text/TextElement.h"

using namespace std;

class Button : public Element {
	public:
        Button();
        Button(unsigned int x, unsigned int y);
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height, string txt);
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height, ImageElement* img);
        void setBgImg(ImageElement* img);
	   void setText(string txt);

	protected:
		TextElement* _textE;
	    ImageElement* _imageE;
};
#endif
