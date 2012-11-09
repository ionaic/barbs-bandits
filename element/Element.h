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
        typedef void(*keyDownCallback_t)(Element*,char);
        typedef void(*mouseMoveCallback_t)(Element*,int,int,int,int);
        typedef void(*mouseClickCallback_t)(Element*,int,int);
        typedef mouseClickCallback_t mouseDownCallback_t;
        typedef mouseClickCallback_t mouseUpCallback_t;
        
        Element(int x, int y); /*!< \brief Construct with position. */
        Element(int x, int y, int xs, int ys); /*!< \brief Construct with position and size. */
        virtual ~Element(); /*!< \brief Destructor */
        /*! \brief Clears the result image to a color (black is default). */
        #define _W_ this->_width
        #define _H_ this->_height
        void clearResult();
        virtual void clearResult(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
        /*! \brief Renders the element and its children recursively. */
        Image* render();

        void registerMouseMoveCallback(mouseMoveCallback_t func); //for now just registers mouse callback
        void registerMouseUpCallback(mouseUpCallback_t func); //for now just registers mouse callback
        void registerKeyDownCallback(keyDownCallback_t func); //for now just registers mouse callback
        /*! \brief Registers a callback function for the element. */
        void registerMouseDownCallback(mouseDownCallback_t func); //for now just registers mouse callback
        /*! \brief Test if element clicked by mouse. */
        virtual void mouseDown(int x, int y);
        void mouseDownRelative(float x, float y);
        virtual void mouseUp(int x, int y);
        void mouseUpRelative(float x, float y);
        virtual void mouseMove(int x, int y, int dx, int dy);
        virtual void keyDown(int c);
        unsigned int width() const { return _width; }
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
        mouseDownCallback_t _mouseCallback;
        mouseUpCallback_t _mouseUpCallback;
        mouseMoveCallback_t _mouseMoveCallback;
        keyDownCallback_t _keyDownCallback;
        vector<Element *> _children;
        /*! The resulting image for the element to be blitted to a parent 
         * element or rendered on a surface 
         */
        Image *_clrImg;
        Image *_result;
        friend class ElementComparison; 

    private:
        Element(); /*!< \brief Default Constructor. */
        float _zIndex;
        unsigned int _id;
        bool _dirty;
        bool _first_render;
        Element *_parent;
};

class ElementComparison {
public:
    inline bool operator()(Element *a, Element *b) {
        return a->_zIndex < b->_zIndex;
    }
};
#endif
