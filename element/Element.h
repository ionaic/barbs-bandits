/*! \file
This file contains the Element class.
*/
#ifndef _ELEMENT_H_
#define _ELEMENT_H_

#include <vector>
#include <algorithm>
#include "../image/Image.h"

using namespace std;

/*! \brief Keeps a rolling count of how many elements have been constructed.
Not for public use! */
static int currentId = 0;

/*! \brief The base class that all GUI elements derive from.

This class provides a standard interface that is required for element
traversal, rendering, and events.
*/
class Element {
    public:
        Element(); /*!< \brief Default Constructor. */
        Element(int x, int y); /*!< \brief Construct with position. */
        Element(int x, int y, int xs, int ys); /*!< \brief Construct with position and size. */
        virtual ~Element(); /*!< \brief Destructor */
        /*! \brief Clears the result image to a color (black is default). */
        virtual void clearResult();
        /*! \brief Renders the element and its children recursively. */
        Image* render();
        /*! \brief Registers a callback function for the element. */
        void registerCallback(void (*func)(void *)); //for now just registers mouse callback
        /*! \brief Test if element clicked by mouse. */
        void mouseInput(int x, int y);
        /*! \brief Add a child element to the current element. */
        void addChild(Element *child);
        // getters and setters
        /*! \brief Set the x position of the element. */
        void setX(unsigned int x) { this->_xCoord = x; }
        /*! \brief Set the y position of the element. */
        void setY(unsigned int y) { this->_yCoord = y; }
        /*! \brief Set the z position (z index) of the element. */
        void setZ(float z) { this->_zIndex = z; }
        /*! \brief Retrieve the current element's unique id. */
        unsigned int getId() { return this->_id; }
        /*! \brief Set the element's width. */
        void setWidth(unsigned int width) { this->_width = width; }
        /*! \brief Set the element's height. */
        void setHeight(unsigned int height) { this->_height = height; }
        /*! \brief Set the dirty flag.  Causes the element re-render. */
        void setDirty(bool dirty) { this->_dirty = dirty; }
        // operator definitions
        /*! \brief Less than operator so Element objects may be sorted. */
        bool operator<(const Element &other);
   
    protected:
        /*! The x position of the element in the parent. */
        unsigned int _xCoord;
        /*! The y position of the element in the parent. */
        unsigned int _yCoord;
        /*! The element's width. */
        unsigned int _width;
        /*! The element's height. */
        unsigned int _height;
        void (*_mouseCallback)(void*);
        /*! The resulting image for the element to be blitted to a parent 
         * element or rendered on a surface 
         */
        Image *_result;
 
    private:
        float _zIndex;
        unsigned int _id;
        bool _dirty;
        vector<Element *> _children;
        Element *_parent;
        Image *_clrImg;
};
#endif
