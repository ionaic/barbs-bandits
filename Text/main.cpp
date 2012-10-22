#include <iostream>
#include <string>
#include "Text.h"

using namespace std;
int main() {
	Text t;
	t.Init(200,40,10,"Fuck you, dickface");
	int e = t.Render();

	cout << e << endl;
	cout << t.stringify() << endl;

	return 0;
}
