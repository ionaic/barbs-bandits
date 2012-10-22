#include <string>
#include <ft2build.h>
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
		string stringify();

	private:
		int width;
		int height;
		unsigned char** image;
		int fontSize;
		string content;
		bool dirty;
		void renderImage(FT_Bitmap* b, int x, int y);
		
};
