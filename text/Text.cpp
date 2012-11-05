#include "Text.h"
#include <string>
#include <ft2build.h>
#include <string>
#include <iostream>
#include "../image/Image.h"
#include "../image/Pixel.h"
#include <stdio.h>
#include <math.h>
#include FT_FREETYPE_H

using namespace std;
/*! Default constructor sets width, height and font size to 0 and content to be an empty string. */
Text::Text() {
	Text(0,0,0,"");
}

/*! Constructor sets width, height and font size as per arguments and then content to be an empty string. */
Text::Text(int width, int height, int size) {
	Text(width,height,size,"");
}

/*! Constructor sets width, height, font size and content as per arguments */
Text::Text(int width, int height, int size, string content) {
	if (size < 0) {
		cerr << "Invliad font size";
		size = 0;
	}

	if (size == 0) {
		int h = height>>1;
		int w = (width/content.size())>>1;
		if (h > w) {
			size = h;
		}else{
			size = w;
		}
	}
	_width = width;
	_height = height;
	_fontSize = size;
	_content = content;
	Pixel p(255,0,0,255);
	_image = NULL;
	_basic = 0;
	_preimg = 0;
	_render();
}

/*! Copy constructor replicates a preexisting text */
Text::Text(Text &txt) {
	Text(txt._width, txt._height, txt._fontSize, txt._content);
}

/*! Destructor deletes dynamically allocated variables */
Text::~Text() {
	if (_image) {
		delete[] _image;
	}
	if (_basic) {
		delete[] _basic;
	}
	if (_preimg) {
		delete[] _preimg;
	}
}

/*! Modify the text and rerender the image */
void Text::setText(string c) {
	_content = c;
	_render();
}

/*! Get the rendered image */
Image* Text::getImage() {
	return _image;
}

/*! Return string of text stored */
string Text::getText() {
	return _content;
}

//Render the text in _content into _image
void Text::_render() {
	//This is based off libttf tutorial code: bit.ly/ROmj5C
	int numChars = _content.size();
	if (_basic) {
		delete[] _basic;
	}
	_basic = new unsigned char[_height*_width];
	//Zero _basic
	for (int i= 0; i < _height*_width; i++) {
		_basic[i] = 0;
	}

	FT_Library	library;
	FT_Face    	face;
	FT_GlyphSlot	slot;
	FT_Error		error;
	FT_Vector 	pen;

	error = FT_Init_FreeType( &library );

	//Load text (ttf) file and return with an error if there's an issue
	error = FT_New_Face( library,	"text/FreeSans.ttf", 0, &face );
	if (error) {
		cerr<< "Error loading .ttf file"<< endl;
		return;
	}

	//Set the text size and return with an error if there's an issue
	error = FT_Set_Char_Size( face, 0, _fontSize * 64, 0, 0 );
	if (error) {
		cerr<< "Error setting font size"<< endl;
		return;
	}

	pen.x = 0;

	slot = face->glyph; //This is a useful shortcut for the rest of the code

	//For each character in _content, render it into _basic
	for (int n = 0; n < numChars; n++ ) {
		error = FT_Load_Char( face, _content[n], FT_LOAD_RENDER);
		if (pen.x + slot->bitmap_left > _width) {
			cerr << "Error rendering text: slot exceeded bitmap width." << endl;
			return;
		}

		_renderImage( &slot->bitmap, pen.x + slot->bitmap_left,
				_height - slot->bitmap_top, _basic);

		pen.x += slot->advance.x >> 6;
	}

	//Destructors
	FT_Done_Face    ( face );
	FT_Done_FreeType( library );

	//Turn the basic array into an rgba array
	_colorify(_basic);
}


//Do a binary or to combine each character into _basic based off the character's position
void Text::_renderImage( FT_Bitmap*  bitmap, FT_Int x, FT_Int y, unsigned char _basic[]) {
	FT_Int  i, j, p, q;
	FT_Int  x_max = x + bitmap->width;
	FT_Int  y_max = y + bitmap->rows;
	unsigned int index = 0;

	for ( i = x, p = 0; i < x_max; i++, p++ ) {
		for ( j = y, q = 0; j < y_max; j++, q++ ) {
			if ( i < 0  || j < 0 || i >= _width || j >= _height ) { continue; }
			index = (_height - j) * _width - (_width - i);
			_basic[index] |= bitmap->buffer[q * bitmap->width + p];
		}
	}
}

//Helper function to print an approximation of the text imgae as asci art
void Text::show_image( unsigned char _basic[] ) {
	for (int i = 0; i < _height; i++ ) {
		for (int j = 0; j < _width; j++ ) {
			if(_basic[i*_height+j] == 0) cout << ' ';
			else if(_basic[i*_height+j] < 128) cout << '+';
			else if(_basic[i*_height+j] < 128) cout << '*';
			cout << endl;
		}
	}
}

//Take _basic and generage _image as an rgba array with r, g and b set to zero and alpha set to the corresponding value of basic
void Text::_colorify(unsigned char _basic[]) {
	if (_preimg==0) {
		delete[] _preimg;
		_preimg = 0;
	}
	_preimg = new unsigned char[_height*_width*4];

	for (int i = 0; i<_height*_width*4; i+=4) {
		_preimg[i] = 0;
		_preimg[i+1] = 0;
		_preimg[i+2] = 0;
		_preimg[i+3] = _basic[i/4];
	}
	_image = new Image(_width,_height,_preimg);
}
