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

		void SetText(string c);
		int Render();
		string Stringify();

		unsigned char* rendered;


	private:
		int* image;
		int width;
		int height;
		int fontSize;
		bool dirty;
		string content;

		void RenderImage(FT_Bitmap* b, int x, int y);
		void GenerateImage();
		
};
#endif
