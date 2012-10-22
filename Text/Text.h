#include <string>
#include <ft2build.h>
#include "../image/Pixel.h"
#include "../image/Image.h"
#include FT_FREETYPE_H

using namespace std;

class Text {
	public:
		Text();
		~Text();

		void Init(int w, int h, int size);
		void Init(int w, int h, int size, string c);
		void SetText(string c);
		int Render();
		string Stringify();

		Image* rendered;


	private:
		int width;
		int height;
		unsigned char** image;
		int fontSize;
		bool dirty;
		string content;
		Pixel** pixels;

		void RenderImage(FT_Bitmap* b, int x, int y);
		void GenerateImage();
		
};
