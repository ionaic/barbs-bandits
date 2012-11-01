/*! \file
This file contains the TextElement class.
*/
#ifndef _TEXT_ELEMENT_H_
#define _TEXT_ELEMENT_H_

#include <string>
#include "Text.h"
#include "../image/Image.h"
#include "../element/Element.h"

/*! \brief The class used to store elements of Text. */
class TextElement : public Element {
    public:
        TextElement(unsigned int x, unsigned int y); /*!< \brief Constructor. Sets x and y position of Element. */

        TextElement(unsigned int x, unsigned int y, unsigned int width,
        		unsigned int height); /*!< \brief Constructor. Sets x and y position of Element along with height and width. */

        TextElement(unsigned int x, unsigned int y, unsigned int width,
        		unsigned int height, int size, string txt); /*!< \brief Constructor. Sets x and y position of Element along with height, width, font size and content. */

        ~TextElement(); /*!< \brief Destructor */
        void setText(string txt); /*!< \brief Updates the text stored and re-renders the result. */

        void clearResult(); /*!< \brief Clears the rendered image previously stored */

    private: 
        Text* _text;
};
#endif
