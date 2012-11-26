/*! \file
This file contains the Button class.
*/
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <string>
#include "Image.h"
#include "Text.h"
#include "Element.h"
#include "ImageElement.h"
#include "TextElement.h"

using namespace std;

/*! \brief The class used to store a Button consisting of a background ImageElement and a foreground TextElement. */
class Button : public Element {
	public:
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height); /*!< \brief Constructor. Sets x and y position of Element along with height and width. */
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height, string txt); /*!< \brief Constructor. Sets x and y position of Element along with height, width, and text. */
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height,
                const char* up_file, const char* down_file, string text); /*!< \brief Constructor. Sets x and y position of Element along width height. Loads up and down images */
        void setUpImage(int width, int height, const char* up_file);/*!< \brief Sets background image for up. */
        void setDownImage(int width, int height, const char* down_file);/*!< \brief Sets background image for down. */
	    void setText(string txt); /*!< \brief Sets text. */
	    void mouseDown(int x, int y);
	    void mouseUp(int x, int y);

	protected:
	    void _switch();
	    bool _down;
		TextElement* _textE;
	    ImageElement* _imageUp;
	    ImageElement* _imageDown;
};
#endif
