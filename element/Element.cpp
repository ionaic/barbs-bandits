#include "Element.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "../image/Image.h"

using namespace std;

/*! Creates an element positioned at (0,0) with dimensions (0,0). */
Element::Element() {
    cout << "invalid element 1" << endl;
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
    this->_mouseUpCallback = 0;
    this->_mouseMoveCallback = 0;
}

/*! Creates an element positioned at (x,y) with dimensions (0,0). */
Element::Element(int x, int y) {
    cout << "invalid element 2" << endl;
	this->_xCoord = x;
	this->_yCoord = y;
	this->_width = 0;
	this->_height = 0;
    this->_id = currentId;
    currentId++;
    this->_result = new Image(this->_width, this->_height);
    this->_clrImg = new Image(this->_width, this->_height);
    this->_dirty = true;
    this->_mouseCallback = 0;
    this->_mouseUpCallback = 0;
    this->_mouseMoveCallback = 0;
}



/*! Creates an element positioned at (x, y) with dimensions (xs, ys). */
Element::Element(int x, int y, int xs, int ys) {
    cout << "element" << x << y << ", " << xs << " , " << ys << endl;
	this->_xCoord = x;
	this->_yCoord = y;
	this->_width = xs;
	this->_height = ys;
    this->_id = currentId;
    currentId++;
    this->_result = new Image(this->_width, this->_height);
    this->_clrImg = new Image(this->_width, this->_height);
    this->_dirty = true;
    this->_mouseCallback = 0;
    this->_mouseUpCallback = 0;
    this->_mouseMoveCallback = 0;
}


/*! Deletes the pointers for the result image and the clear image (background). */
Element::~Element() {
    delete this->_result;
    delete this->_clrImg;
    for (vector<Element *>::iterator itr = _children.begin(); _children.end() != itr; itr++) { 
        delete *itr; 
    }
}

/*! Renders the background of the element, namely element contents.  For generic 
 * Elements, it blits a solid color (black) image to the element's result image.
 * For content elements (TextElement and ImageElement) it will blit the
 * stored image (for image elements) or resulting image from rendering the text
 * (for text elements) before rendering the children.
 */
void Element::clearResult() {
    //clear the image to alpha
    this->_result->set(0, 0, _width, _height, Pixel(0,0,0,0));
    //start drawing things
    this->_clrImg->blit(*(this->_result), 0U, 0U, 0U, 0U, this->_width, this->_height);
}

/*! Tests if the mouse click at (x, y) is within the element. */
void Element::mouseDown(int x, int y) {
	if ( x < 0 || y < 0) return;
	vector<Element*>::iterator child = this->_children.begin();
	for(; _children.end() != child; child++) {
		(*child)->mouseDown(x-(*child)->_xCoord, y-(*child)->_yCoord);
	}
	bool inside = (this->_width >= x && this->_height >= y);
	if (inside) { //if inside button
		if (0 != _mouseCallback ) //if element has a callback
			this->_mouseCallback(this,x,y);
		return;
	}
}

/*! Tests if the mouse click at (x, y) is within the element. */
void Element::mouseUp(int x, int y) {
	if ( x < 0 || y < 0) return;
	vector<Element*>::iterator child = this->_children.begin();
	for(; _children.end() != child; child++) {
		(*child)->mouseUp(x-(*child)->_xCoord, y-(*child)->_yCoord);
	}
	bool inside = (this->_width >= x && this->_height >= y);
	if (inside) { //if inside button
		if (0 != _mouseUpCallback ) //if element has a callback
			this->_mouseUpCallback(this,x,y);
		return;
	}
}

/*! Tests if the mouse click at (x, y) is within the element. */
void Element::mouseMove(int x, int y, int dx, int dy) {
	if ( x < 0 || y < 0) return;
	vector<Element*>::iterator child = this->_children.begin();
	for(; _children.end() != child; child++) {
		(*child)->mouseMove(dx-(*child)->_xCoord, y-(*child)->_yCoord, dx, dy);
	}
	bool inside = (this->_width >= x && this->_height >= y);
	if (inside) { //if inside button
		if (0 != _mouseMoveCallback ) //if element has a callback
			this->_mouseMoveCallback(this,x,y,dx,dy);
		return;
	}
}

/*! Register a callback function, accepts a function pointer to a function which
 * takes one argument of void*.
 */
void Element::registerMouseDownCallback(mouseDownCallback_t func) {
    this->_mouseCallback = func;
}

void Element::registerMouseUpCallback(mouseUpCallback_t func) {
    this->_mouseUpCallback = func;
}

void Element::registerMouseMoveCallback(mouseMoveCallback_t func) {
    this->_mouseMoveCallback = func;
}

/*! Add a child element to the set of children elements.  The function accepts a
 * pointer to an Element, which must remain in scope as long as the parent. Calls
 * STL sort on the children, organizing by z-index (z position).
 */
void Element::addChild(Element *child) {
	if (this->_id != child->_id) {
		this->_children.push_back(child);
		sort(this->_children.begin(), this->_children.end());
		return;
	}
	cout << "Element could not be added as child of itself." << endl;
}

/*! Clears the result image of past renders with clearResult(), filling it with
 * either a color or the element's content, then renders each child in order of
 * z-index (z position).  Once all of the children have been rendered, it is
 * blitted to the result image.  After all children are rendered and blitted,
 * the result image is returned.
 */
Image* Element::render() {
    // clear the background of the image, fill with either content or
    //  a clear color
    this->clearResult();

	vector<Element*>::iterator child = this->_children.begin();
	for(; _children.end() != child; child++) {
		Image* childImage = (*child)->render();
		//if ((*child)->_dirty) {
        //render the children onto the element's background
        //return composited image/texture
        // blit each child to the result image at the proper place
        childImage->blit(*(this->_result), 0, 0, 
            (*child)->_xCoord, (*child)->_yCoord, 
            (*child)->_width, (*child)->_height);
        // if any child is dirty, this element is dirty
		//}
		this->_dirty = (*child)->_dirty || this ->_dirty;
	}
	//cout << "Rendering ID: "<< this->_id << endl;
    return this->_result;
}

/*! Less than operator which compares two elements based solely on their
 *  z-index (z position).
 */
bool Element::operator<(const Element &other) { 
    return this->_zIndex < other._zIndex;
}
