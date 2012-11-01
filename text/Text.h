/*! \file
This file contains the Text class.
*/
#ifndef _TEXT_H_
#define _TEXT_H_

#include <string>
#include <ft2build.h>
#include "../image/Image.h"
#include FT_FREETYPE_H

using namespace std;

//The end user shouldn't directly access this class. All interactions should go through TextElement

/*! \brief The class used to store text and render text into an Image object

This class should not be accessed directly. Instead, interactions should go through ImageElement.
*/
class Text {
	public:
		Text(); /*!< \brief Default Constructor. */
		Text(Text &txt); /*!< \brief Copy Constructor. */
		Text(int w, int h, int size); /*!< \brief Constructor with width, height and font size. */
		Text(int w, int h, int size, string c); /*!< \brief Constructor with width, height, font size and string of text. */
		~Text(); /*!< \brief Destructor */

		void setText(string c); /*!< \brief Update the text stored and re-render it*/
		Image* getImage(); /*!< \brief Returns a pointer to the rendered image */
		string getText(void); /*!< \brief Returns the text stored */

	private:
		Image* _image;
		int _width;
		int _height;
		int _fontSize;
		string _content;
		void _render();

		void show_image(unsigned char _basic[]);
		unsigned char *_basic;
		unsigned char *_preimg;

		void _renderImage(FT_Bitmap* b, int x, int y, unsigned char _basic[]);
		void _colorify(unsigned char _basic[]);
		
};
#endif
