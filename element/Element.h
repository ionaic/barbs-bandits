#ifndef _ELEMENT_H_
#define _ELEMENT_H_
/* element.h
 * render : renders the element to the screen
 *
 */

#include <vector>
#include <algorithm>
#include "../image/Image.h"

using namespace std;

static int currentId = 0;

class Element {
    public:
        Element();
        Element(int x, int y);
        Element(int x, int y, int xs, int ys);
        virtual ~Element();
        virtual void clearResult() { 
            this->_clrImg->blit(*(this->_result), 0U, 0U, 0U, 0U, this->_width, this->_height);
        }
        Image* render();
        void registerCallback(void (*func)()); //for now just registers mouse callback
        //void mouseInput(int x, int y);
        void addChild(Element *child);
        // getters and setters
        void setX(unsigned int x) { this->_xCoord = x; }
        void setY(unsigned int y) { this->_yCoord = y; }
        void setZ(float z) { this->_zIndex = z; }
        void setWidth(unsigned int width) { this->_width = width; }
        void setHeight(unsigned int height) { this->_height = height; }
        void setDirty(bool dirty) { this->_dirty = dirty; }
        // operator definitions
        bool operator<(const Element &other) { return this->_zIndex < other._zIndex; }
   
    protected:
        unsigned int _xCoord;
        unsigned int _yCoord;
        unsigned int _width;
        unsigned int _height;
        unsigned int _id;
        Image *_result;
 
    private:
        float _zIndex;
        bool _dirty;
        vector<Element *> _children;
        Element *_parent;
        void (*_mouseCallback)();
        Image *_clrImg;
};
#endif
