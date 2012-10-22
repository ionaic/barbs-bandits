#include "element.h"
#include <iostream>
#include <stdio.h>

using namespace std;


Element::Element() {
    this->xCoord = 0;
    this->yCoord = 0;
    this->xSize = 0;
    this->ySize = 0;
    this->id = currentId;
    currentId++;
}


Element::Element(int x, int y, int xs, int ys) {
	this->xCoord = x;
	this->yCoord = y;
	this->xSize = xs;
	this->ySize = ys;
    this->id = currentId;
    currentId++;
}


void Element::mouseInput(int x, int y) {
	int xMin = this->xCoord;
	int yMin = this->yCoord;
	int xMax = this->xCoord + this->xSize;
	int yMax = this->yCoord + this->ySize;
	bool inside = (xMin <= x && yMin <= y && xMax >= x && yMax >= y);
	if (inside) {
		cout << "hit! id: " << this->id << endl;
		return;
	}
	cout << "miss! id: " << this->id << endl;
}


void Element::render() {
	vector <Element>::iterator child;
	child = this->children.begin();
	while(children.end() != child ) {
		child->render();
		if (child->dirty) {
			//here's where we actually want to do the rendering
		}
	}
}


int main() {
	vector <Element> elements;
	for(unsigned int i = 0; i < 10; i++) {
		Element e(0,0,100,100);
		elements.push_back(e);
	}

	for(unsigned int i =0; i < elements.size(); i++) {
		elements[i].mouseInput(i * 20, i * 20);
	}
}
