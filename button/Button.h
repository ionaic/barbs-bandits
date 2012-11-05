/*! \file
This file contains the Button class.
*/
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <string>
#include "../image/Image.h"
#include "../text/Text.h"
#include "../element/Element.h"
#include "../image/ImageElement.h"
#include "../text/TextElement.h"

using namespace std;

/*! \brief The class used to store a Button consisting of a background ImageElement and a foreground TextElement. */
class Button : public Element {
	public:
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height); /*!< \brief Constructor. Sets x and y position of Element along with height and width. */
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height, string txt); /*!< \brief Constructor. Sets x and y position of Element along with height, width, and text. */
        Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height, ImageElement* img); /*!< \brief Constructor. Sets x and y position of Element along width height. Uses an ImageElment as the background image. */
        void setBgIg(ImageElement* img); /*!< \brief Sets background image. */
	    void setText(string txt); /*!< \brief Sets text. */

	protected:
		TextElement* _textE;
	    ImageElement* _imageE;
};
#endif
