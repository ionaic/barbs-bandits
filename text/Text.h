#ifndef _TEXT_H_
#define _TEXT_H_

#include <string>
#include <ft2build.h>
#include "../image/Image.h"
#include FT_FREETYPE_H

using namespace std;

//The end user shouldn't directly access this class. All interactions should go through TextElement
class Text {
	public:
		Text();
		Text(Text &txt);
		Text(int w, int h, int size);
		Text(int w, int h, int size, string c);
		~Text();

		void setText(string c);
		Image* getImage();
		string getText(void) {return _content;}

	private:
		Image* _image;
		int _width;
		int _height;
		int _fontSize;
		string _content;
		void _render();

		void show_image(unsigned char _basic[]);
		unsigned char *_basic;
		unsigned char *_preimg;

		void _renderImage(FT_Bitmap* b, int x, int y, unsigned char _basic[]);
		void _colorify(unsigned char _basic[]);
		
};
#endif
