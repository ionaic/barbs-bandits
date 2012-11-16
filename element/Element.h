/*! \file
This file contains the Element class.
*/
#ifndef _ELEMENT_H_
#define _ELEMENT_H_

#include <vector>
#include <algorithm>
#include "Image.h"

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
        typedef void(*keyDownCallback_t)(Element*,char); /*!< \brief function callback type for the keyDown event */
        typedef void(*mouseMoveCallback_t)(Element*,int,int,int,int); /*!< \brief function callback type for the mouseMove event */
        typedef void(*mouseClickCallback_t)(Element*,int,int); /*!< \brief function callback type for the mouseClick event */
        typedef mouseClickCallback_t mouseDownCallback_t; /*!< \brief function callback type for the mouseDown event */
        typedef mouseClickCallback_t mouseUpCallback_t; /*!< \brief function callback type for the mouseUp event */
        
        Element(int x, int y); /*!< \brief Construct with position. */
        Element(int x, int y, int xs, int ys); /*!< \brief Construct with position and size. */
        virtual ~Element(); /*!< \brief Destructor */
        /*! \brief Clears the result image to a color (black is default). */
        virtual void clearResult();
        /*! \brief Renders the element and its children recursively. */
        Image* render();
        /*! \brief registers function callback type for the mouseMove event */
        void registerMouseMoveCallback(mouseMoveCallback_t func);
        /*! \brief registers function callback type for the mouseUp event */
        void registerMouseUpCallback(mouseUpCallback_t func);
        /*! \brief registers function callback type for the keyDown event */
        void registerKeyDownCallback(keyDownCallback_t func);
        /*! \brief registers function callback type for the mouseDown event */
        void registerMouseDownCallback(mouseDownCallback_t func);
        /*! \brief Tests if the mouse click down at (x, y) is within the element. */
        virtual void mouseDown(int x, int y);
        /*! \brief mouseDown call that gives only relative movement since the last call */
        void mouseDownRelative(float x, float y);
        /*! \brief Tests if the mouse click up at (x, y) is within the element. */
        virtual void mouseUp(int x, int y);
        /*! \brief mouseUp call that gives only relative movement since the last call */
        void mouseUpRelative(float x, float y);
        /*! \brief Tests if the mouse click down at (x, y) is within the element. */
        virtual void mouseMove(int x, int y, int dx, int dy);
        /*! \brief Provides an interface for key press event callbacks */
        virtual void keyDown(int c);
        /*! \brief returns the width of the element */
        unsigned int width() const { return _width; }
        /*! \brief returns the height of the element */
        unsigned int height() const { return _height; }
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
        void setDirty(bool dirty);
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
        /*! The element's mouseDowncallback function */
        mouseDownCallback_t _mouseCallback;
        /*! The element's mouseUpcallback function */
        mouseUpCallback_t _mouseUpCallback;
        /*! The element's mouseMovecallback function */
        mouseMoveCallback_t _mouseMoveCallback;
        /*! The element's keyDowncallback function */
        keyDownCallback_t _keyDownCallback;
        /*! The element's child list */
        vector<Element *> _children;
        /*! The resulting image for the element to be blitted to a parent 
         * element or rendered on a surface 
         */
        Image *_result;
        /*! blank image that the element will be reset to */
        Image *_clrImg;
        friend class ElementComparison; 
    private:
        Element(); /*!< \brief Default Constructor. */
        float _zIndex;
        unsigned int _id;
        bool _dirty;
        bool _first_render;
        Element *_parent;
};

/*! \brief helper class that is used to compare the Z indices of two elements */
class ElementComparison {
public:
    inline bool operator()(Element *a, Element *b) {
        return a->_zIndex < b->_zIndex;
    }
};
#endif
