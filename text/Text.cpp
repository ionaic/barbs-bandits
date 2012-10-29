#include "Text.h"
#include <string>
#include <ft2build.h>
#include <string>
#include <iostream>
#include "Image.h"
#include "Pixel.h"
#include <stdio.h>
#include <math.h>
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
	Pixel p(255,0,0,255);
	_image = NULL;//new Image(w, h, p);
	_render();
}

Text::~Text() {
	//delete[] _image; //Broken?
}


void Text::setText(string c) {
	_content = c;
	_render();
}

Image* Text::getImage() {
	return _image;
}

void Text::_render() {
	//This is based off libttf tutorial code: bit.ly/ROmj5C
	int numChars = _content.size();
	unsigned char _binary[_height*_width];
	//Zero _binary
	for (int i= 0; i < _height*_width; i++) {
		_binary[i] = 0;
	}

	FT_Library	library;
	FT_Face    	face;
	FT_GlyphSlot	slot;
	FT_Error		error;
	FT_Vector pen;
	int            n;

	error = FT_Init_FreeType( &library );

	error = FT_New_Face( library,	"text/FreeSans.ttf", 0, &face );
	if (error) {
		cerr<< "Error loading .ttf file"<< endl;
		return;
	}

	error = FT_Set_Char_Size( face, 0, _fontSize * 64, 0, 0 );
	if (error) {
		cerr<< "Error setting font size"<< endl;
		return;
	}

	pen.x = 0;

	slot = face->glyph;

	for ( n = 0; n < numChars; n++ ) {
		/* load glyph image into this slot and erase the previous one */
		error = FT_Load_Char( face, _content[n], FT_LOAD_RENDER );
		if (pen.x + slot->bitmap_left > _width) return;

		_renderImage( &slot->bitmap,
				pen.x + slot->bitmap_left,
				_height - slot->bitmap_top, _binary);

		pen.x += slot->advance.x >> 6;
	}

	FT_Done_Face    ( face );
	FT_Done_FreeType( library );

	show_image(_binary);
	_colorify(_binary);
}

void Text::_renderImage( FT_Bitmap*  bitmap,
		FT_Int x, FT_Int y, unsigned char _binary[]) {
	FT_Int  i, j, p, q;
	FT_Int  x_max = x + bitmap->width;
	FT_Int  y_max = y + bitmap->rows;

	for ( i = x, p = 0; i < x_max; i++, p++ ) {
		for ( j = y, q = 0; j < y_max; j++, q++ ) {
			if ( i < 0  || j < 0 || i >= _width || j >= _height )
				continue;

			_binary[j*_height+i] |= bitmap->buffer[q * bitmap->width + p];
		}
	}
}

void Text::show_image( unsigned char _binary[] ) {
  int  i, j;


  for ( i = 0; i < _height; i++ )
  {
    for ( j = 0; j < _width; j++ )
      putchar( _binary[i*_height+j] == 0 ? ' '
                                : _binary[i*_height + j] < 128 ? '+'
                                                    : '*' );
    putchar( '\n' );
  }
}

void Text::_colorify(unsigned char _binary[]) {
	unsigned char _preimg[_height*_width*4];
	for (int i = 0; i<_height; i++) {
		for (int j = 0; j<_width; j++) {
			unsigned char v = _binary[j*_height+i];
			int vb =  _binary[j*_height+i];
			if (vb != 0)
			cout << vb << endl;
			_preimg[i*j] = 0;
			_preimg[i*j+1] = 0;
			_preimg[i*j+2] = 0;
			_preimg[i*j+3] = 255*(vb!=0);
		}
	}
	_image = new Image(_width,_height,_preimg);

}
