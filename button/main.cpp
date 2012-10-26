#include <string>
#include "../image/Image.h"
#include "../image/Pixel.h"
#include "../text/Text.h"
#include "Button.h"

using namespace std;

int main() {
	Pixel p(255,0,0);
	Image i(40,20,p);
	Button b(0U,40U,20U,10U);
    ImageElement *ie = new ImageElement(0, 0, i)
    b.setBGImg();

	return 0;
}
