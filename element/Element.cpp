#include "Element.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "Image.h"

using namespace std;


Element::Element() {
    this->_xCoord = 0;
    this->_yCoord = 0;
    this->_width = 0;
    this->_height = 0;
    this->_id = currentId;
    currentId++;
    this->_dirty = true;
    this->_result = new Image(this->_width, this->_height);
    this->_clrImg = new Image(this->_width, this->_height);
}


Element::Element(int x, int y) {
	this->_xCoord = x;
	this->_yCoord = y;
	this->_width = 0;
	this->_height = 0;
    this->_id = currentId;
    currentId++;
    this->_dirty = true;
    this->_result = new Image(this->_width, this->_height);
    this->_clrImg = new Image(this->_width, this->_height);
}


Element::Element(int x, int y, int xs, int ys) {
	this->_xCoord = x;
	this->_yCoord = y;
	this->_width = xs;
	this->_height = ys;
    this->_id = currentId;
    currentId++;
    this->_dirty = true;
    this->_result = new Image(this->_width, this->_height);
    this->_clrImg = new Image(this->_width, this->_height);
}

Element::~Element() {

    for (vector<Element*>::iterator itr = this->_children.begin(); itr != this->_children.end(); itr++) {
        delete *itr;
    }
    delete this->_result;
    delete this->_clrImg;
}

//void Element::mouseInput(int x, int y) {
//	int xMin = this->xCoord;
//	int yMin = this->yCoord;
//	int xMax = this->xCoord + this->width;
//	int yMax = this->yCoord + this->height;
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
    std::cout << "in render" << std::endl;
    // clear the background of the image
    this->clearResult();
    std::cout << "num children: " << this->_children.size() << std::endl;
    
	vector<Element*>::iterator child = this->_children.begin();
	while(this->_children.end() != child ) {
		Image* childImage = (*child)->render();
		if ((*child)->_dirty) {
            std::cout << "child is dirty" << std::endl;
			//here's where we actually want to do the rendering
            //return composited image/texture
            // blit each child to the result image at the proper place
            childImage->blit(*(this->_result), 0, 0, 
                (*child)->_xCoord, (*child)->_yCoord, 
                (*child)->_width, (*child)->_height);
            // if any child is dirty, this element is dirty
            this->_dirty = true;
		}
        else {
            this->_dirty = this->_dirty || false;
            std::cout << "child is clean, is this element dirty?: " << this->_dirty << std::endl;
        }
	}
    return this->_result;
}
