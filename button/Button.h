#include <string>
#include "../image/Image.h"
#include "../text/Text.h"

using namespace std;

class Button {
	public:
		Button(string content, int w, int h, int size, Image image);
		~Button();

	private:
		Text* text;
		Image image;

		int width;
		int height;
		
};
