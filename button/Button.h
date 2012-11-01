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
        Button() : Element() {}
        Button(unsigned int x, unsigned int y) { Button(x, y, 0, 0); }
        //TODO: this one is broken because of the zero fontsize text bug (below)
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height) { Button(x, y, width, height, "null"); }

        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height, string txt) : Element(x, y, width, height) {
        	cout << "creating button" << endl;
        	unsigned int size = 14; //TODO: do math based on width and height -> be careful, if the font / text is too long, it just wont draw
        	_imageE = new ImageElement(0, 0, width, height); //need to draw image first
        	addChild(_imageE);
        	_textE = new TextElement(0, 0, width, height, size, txt);
        	addChild(_textE);
        }
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height, ImageElement* img) : Element(x, y, width, height) {
        	_imageE = img;									//need to draw image first
        	addChild(_imageE);
        	_textE = new TextElement(0, 0, width, height);
        	addChild(_textE);
        }
        void setBgImg(ImageElement* img) { Element::addChild(img); }
		//virtual ~Button();
		void setText(string txt) { _textE->setText(txt); }

	protected:
		TextElement* _textE;
	    ImageElement* _imageE;
};
#endif
