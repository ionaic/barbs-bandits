#include <iostream>
#include <string>
#include "Text.h"
#include "../image/Image.h"

using namespace std;
int main() {
	Text t(200,40,10,"Hello World!");
	int e = t.Render();

	cout << e << endl;
	cout << t.Stringify() << endl;
	
	cout << *t.rendered << endl;


	return 0;
}
