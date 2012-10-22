#include <iostream>
#include <vector>
#include "element.h"


int main() {
	vector<Element> elements;
	for(unsigned int i = 0; i < 10; i++) {
		Element e(0,0,100,100);
		elements.push_back(e);
	}
    std::cout << "Created everything." << std::endl;
    
	for(unsigned int i =0; i < elements.size(); i++) {
		//elements[i].mouseInput(i * 20, i * 20);
        elements[i].render();
	}
    std::cout << "Rendered everything." << std::endl;

    return 0;
}
