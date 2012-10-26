#ifndef _TEXT_H_
#define _TEXT_H_

#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H

using namespace std;

class Text {
	public:
		Text(int w, int h, int size);
		Text(int w, int h, int size, string c);
		~Text();

		void setText(string c);
		int render();
		string stringify();

		unsigned char* rendered;


	private:
		unsigned char* _image;
		int _width;
		int _height;
		int _fontSize;
		bool _dirty;
		string _content;

		void _renderImage(FT_Bitmap* b, int x, int y);
		void _generateImage();
		
};
#endif
