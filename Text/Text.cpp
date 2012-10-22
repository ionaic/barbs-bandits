#include "Text.h"
#include <string>
#include <ft2build.h>
#include <string>
#include <iostream>

#include FT_FREETYPE_H

using namespace std;

Text::Text() {
	width = 0;
	height = 0;
	fontSize = 0;
	dirty = false;
}

Text::~Text() {
	if (!image) return;
	for(int i = 0; i < height; ++i) {
		delete[] image[i];
	}
	delete[] image;
}

void Text::Init(int w, int h, int size) {
	Init(w,h,size,"");
}

void Text::Init(int w, int h, int size, string c) {
	width = w;
	height = h;
	fontSize = size;
	content = c;

	image = new unsigned char*[height];
	for(int i = 0; i < height; ++i)
		image[i] = new unsigned char[width];
}

void Text::SetText(string c) {
	content = c;
}

int Text::Render() {
	//This is based off libttf tutorial code: bit.ly/ROmj5C
	if (!image) return -1;

	int num_chars = content.size();

	FT_Library	library;
	FT_Face    	face;
	FT_GlyphSlot	slot;
	FT_Error		error;
	int            pen_x,n;

	error = FT_Init_FreeType( &library );

	error = FT_New_Face( library,	"/usr/share/fonts/TTF/FreeSans.ttf", 0, &face );
	if (error) {
	    	cerr<< "Error loading .ttf file"<< endl;
		return -2;
	}

	error = FT_Set_Char_Size( face, fontSize * 64, 0, 100, 0 );
	if (error) {
		cerr<< "Error setting font size"<< endl;
		return -3;
	}

	pen_x = 0;

	slot = face->glyph;

	for ( n = 0; n < num_chars; n++ ) {
		/* load glyph image into this slot and erase the previous one */
		error = FT_Load_Char( face, content[n], FT_LOAD_RENDER );
		if (pen_x + slot->bitmap_left > width) return -4;

		renderImage( &slot->bitmap,
				pen_x + slot->bitmap_left,
				height - slot->bitmap_top);

		pen_x += slot->advance.x >> 6;
	}

	FT_Done_Face    ( face );
	FT_Done_FreeType( library );
}

void Text::renderImage( FT_Bitmap*  bitmap,
		FT_Int x, FT_Int y) {
	FT_Int  i, j, p, q;
	FT_Int  x_max = x + bitmap->width;
	FT_Int  y_max = y + bitmap->rows;

	for ( i = x, p = 0; i < x_max; i++, p++ ) {
		for ( j = y, q = 0; j < y_max; j++, q++ ) {
			if ( i < 0  || j < 0 || i >= width || j >= height )
				continue;

			image[j][i] |= bitmap->buffer[q * bitmap->width + p];
		}
	}
}

string Text::stringify() {
	string s = "";
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			if (image[i][j] == 0) s+=" ";
			else if (image[i][j] < 128) s+="+";
			else s+="*";
		}
		s+="\n";
	}
	return s;
}
