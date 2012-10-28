#include "Text.h"
#include <string>
#include <ft2build.h>
#include <string>
#include <iostream>
#include FT_FREETYPE_H

using namespace std;
Text::Text() {
	Text(0,0,0,"");
}

Text::Text(int w, int h, int size) {
	Text(w,h,size,"");
}

Text::Text(Text &txt) {
    Text(txt._width, txt._height, txt._fontSize, txt._content);
}

Text::Text(int w, int h, int size, string c) {
	_width = w;
	_height = h;
	_fontSize = size;
	_content = c;
	_dirty = false;
	_image = new unsigned char[_height*_width];
	rendered = new unsigned char[_height*_width*4];
}

Text::~Text() {
	delete[] _image;
}


void Text::setText(string c) {
	_content = c;
}

int Text::render() {
	//This is based off libttf tutorial code: bit.ly/ROmj5C
	int numChars = _content.size();

	FT_Library	library;
	FT_Face    	face;
	FT_GlyphSlot	slot;
	FT_Error		error;
	int            pen_x,n;

	error = FT_Init_FreeType( &library );

	error = FT_New_Face( library,	"text/FreeSans.ttf", 0, &face );
	if (error) {
		cerr<< "Error loading .ttf file"<< endl;
		return -2;
	}

	error = FT_Set_Char_Size( face, _fontSize * 64, 0, 100, 0 );
	if (error) {
		cerr<< "Error setting font size"<< endl;
		return -3;
	}

	pen_x = 0;

	slot = face->glyph;

	for ( n = 0; n < numChars; n++ ) {
		/* load glyph image into this slot and erase the previous one */
		error = FT_Load_Char( face, _content[n], FT_LOAD_RENDER );
		if (pen_x + slot->bitmap_left > _width) return -4;

		_renderImage( &slot->bitmap,
				pen_x + slot->bitmap_left,
				_height - slot->bitmap_top);

		pen_x += slot->advance.x >> 6;
	}

	FT_Done_Face    ( face );
	FT_Done_FreeType( library );

	_generateImage();
	return 1;
}

void Text::_renderImage( FT_Bitmap*  bitmap,
		FT_Int x, FT_Int y) {
	FT_Int  i, j, p, q;
	FT_Int  x_max = x + bitmap->width;
	FT_Int  y_max = y + bitmap->rows;

	for ( i = x, p = 0; i < x_max; i++, p++ ) {
		for ( j = y, q = 0; j < y_max; j++, q++ ) {
			if ( i < 0  || j < 0 || i >= _width || j >= _height )
				continue;

			_image[j*_width+i] |= bitmap->buffer[q * bitmap->width + p];
		}
	}
}

string Text::stringify() {
	string s = "";
	for (int i = 0; i<_height; i++) {
		for (int j = 0; j<_width; j++) {
			if (_image[i*_width+j] == 0) s+=" ";
			else if (_image[i*_width+j] < 128) s+="+";
			else s+="*";
		}
		s+="\n";
	}
	return s;
}

void Text::_generateImage() {
	for (int i = 0; i<_height; i++) {
		for (int j = 0; j<_width; j++) {
			int v = _image[i*_width+j];
			for(int k=0; k < 3; k++) {
				rendered[i*_width*4+4*j+k] = 0;
			}
				rendered[i*_width*4+4*j+4] = v;
		}
	}
}
