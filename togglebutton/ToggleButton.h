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
    friend class DropDown;
	public:
        ToggleButton(int x, int y, int w, int h); /*!< \brief Constructor. Sets x and y position of this element along with width and height. */
        ToggleButton(int x, int y, int w, int h, string txt); /*!< \brief Constructor. Sets x and y position of this element along with width, height and text. */
        ToggleButton(int x, int y, int w, int h, 
            const char* up_file, const char* down_file,
            string text); /*!< \brief Constructor. Sets x and y position of this element along with width, height, text, font size, and a background image */
        void mouseDown(int x, int y); /*!< \brief mouseInput overload.  Performs action if inside this element */
        void setDown(bool down); /*! < \brief Allows the user to manually set up or down */
        void mouseUp(int x, int y) {}; /*!< \brief mouseInput overload */
        bool isDown(); /*! < \brief checks if the button is down */
};
#endif
