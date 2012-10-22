#include <string>
#include "../image/Image.h"
#include "../image/Pixel.h"
#include "../text/Text.h"
#include "Button.h"

using namespace std;

int main() {
	Pixel p(255,0,0);
	Image i(40,20,p);
	Button b("Button",40,20,10,i);

	return 0;
}
