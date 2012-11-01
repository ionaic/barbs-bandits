#include "Element.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "../image/Image.h"

using namespace std;

/*! Creates an element positioned at (0,0) with dimensions (0,0). */
Element::Element() {
    this->_xCoord = 0;
    this->_yCoord = 0;
    this->_width = 0;
    this->_height = 0;
    this->_id = currentId;
    currentId++;
    this->_result = new Image(this->_width, this->_height);
    this->_clrImg = new Image(this->_width, this->_height);
    this->_dirty = true;
    this->_mouseCallback = 0;
}

/*! Creates an element positioned at (x,y) with dimensions (0,0). */
Element::Element(int x, int y) {
	this->_xCoord = x;
	this->_yCoord = y;
	this->_width = 0;
	this->_height = 0;
    this->_id = currentId;
    currentId++;
    this->_result = new Image(this->_width, this->_height);
	Pixel p(100, 100, 100, 255);
    this->_clrImg = new Image(this->_width, this->_height, p);
    this->_dirty = true;
    this->_mouseCallback = 0;
}


Element::Element(int x, int y, int xs, int ys) {
	this->_xCoord = x;
	this->_yCoord = y;
	this->_width = xs;
	this->_height = ys;
    this->_id = currentId;
    currentId++;
    this->_result = new Image(this->_width, this->_height);
	Pixel p(100, 100, 100, 255);
    this->_clrImg = new Image(this->_width, this->_height, p);
    this->_dirty = true;
    this->_mouseCallback = 0;
}

Element::~Element() {

    //for (vector<Element*>::iterator itr = this->_children.begin(); itr != this->_children.end(); itr++) {
    //    delete *itr;
    //}
    delete this->_result;
    delete this->_clrImg;
}

void Element::mouseInput(int x, int y) {
	if ( x < 0 || y < 0) return;
	vector<Element*>::iterator child = this->_children.begin();
	for(; _children.end() != child; child++) {
		(*child)->mouseInput(x-(*child)->_xCoord, y-(*child)->_yCoord);
	}
	bool inside = (this->_width >= x && this->_height >= y);
	if (inside) { //if inside button
		if (0 != _mouseCallback ) //if element has a callback
			this->_mouseCallback(this);
		return;
	}
}

void Element::registerCallback(void (*func)(void *)) {
    this->_mouseCallback = func;
}


void Element::addChild(Element *child) {
	if (this->_id != child->_id) {
		this->_children.push_back(child);
		sort(this->_children.begin(), this->_children.end());
		return;
	}
	cout << "Element could not be added as child of itself." << endl;
}


Image* Element::render() {
    // clear the background of the image
    this->clearResult();

	vector<Element*>::iterator child = this->_children.begin();
	for(; _children.end() != child; child++) {
		Image* childImage = (*child)->render();
		if ((*child)->_dirty) {
			//here's where we actually want to do the rendering
            //return composited image/texture
            // blit each child to the result image at the proper place
            childImage->blit(*(this->_result), 0, 0, 
                (*child)->_xCoord, (*child)->_yCoord, 
                (*child)->_width, (*child)->_height);
            // if any child is dirty, this element is dirty
		}
		this->_dirty = (*child)->_dirty || this ->_dirty;
	}
	cout << "Rendering ID: "<< this->_id << endl;
    return this->_result;
}
