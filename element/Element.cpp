#include "Element.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "Image.h"

using namespace std;


Element::Element() {
    this->_xCoord = 0;
    this->_yCoord = 0;
    this->_xSize = 0;
    this->_ySize = 0;
    this->_id = currentId;
    currentId++;
}


Element::Element(int x, int y, int xs, int ys) {
	this->_xCoord = x;
	this->_yCoord = y;
	this->_xSize = xs;
	this->_ySize = ys;
    this->_id = currentId;
    currentId++;
}


//void Element::mouseInput(int x, int y) {
//	int xMin = this->xCoord;
//	int yMin = this->yCoord;
//	int xMax = this->xCoord + this->xSize;
//	int yMax = this->yCoord + this->ySize;
//	bool inside = (xMin <= x && yMin <= y && xMax >= x && yMax >= y);
//	if (inside) {
//		cout << "hit! id: " << this->id << endl;
//		return;
//	}
//	cout << "miss! id: " << this->id << endl;
//}

void Element::registerCallback(void (*func)()) {
    this->_mouseCallback = func;
}


void Element::addChild(Element *child) {
    this->_children.push_back(child);
    sort(this->_children.begin(), this->_children.end());
}


Image* Element::render() {
	vector<Element*>::iterator child = this->_children.begin();
	while(this->_children.end() != child ) {
		Image* childImage = (*child)->render();
		if ((*child)->_dirty) {
			//here's where we actually want to do the rendering
            //return composited image/texture
            // blit each child to the result image at the proper place
            childImage->blit(*(this->_result), 0, 0, 
                (*child)->_xCoord, (*child)->_yCoord, 
                (*child)->_xSize, (*child)->_ySize);
            // if any child is dirty, this element is dirty
            this->_dirty = true;
		}
	}
    return this->_result;
}
