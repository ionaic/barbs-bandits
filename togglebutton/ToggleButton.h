/*! \file
This file contains the ToggleButton class.
*/
#ifndef _TOGGLE_BUTTON_H_
#define _TOGGLE_BUTTON_H_

#include <string>
#include "../image/ImageElement.h"
#include "../text/TextElement.h"
#include "../text/Text.h"
#include "../button/Button.h"

using namespace std;

/*! \brief The class used to store toggleable Buttons. */
class ToggleButton: public Button {
	public:
        ToggleButton(int x, int y, int w, int h); /*!< \brief Constructor. Sets x and y position of this element along with width and height. */
        ToggleButton(int x, int y, int w, int h, string txt); /*!< \brief Constructor. Sets x and y position of this element along with width, height and text. */
        ToggleButton(int x, int y, int w, int h, 
            string content, int size, ImageElement* i); /*!< \brief Constructor. Sets x and y position of this element along with width, height, text, font size, and a background image */
        void mouseDown(int x, int y); /*!< \mouseInput overload.  Performs action if inside this element */
        void setDown(bool down); /*! < \ Allows the user to manually set up or down */
        bool isDown();
	private:
	    bool _down;
	    void _update();
};
#endif
