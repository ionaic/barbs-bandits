/*! \file
This file contains the TextEdit class.
*/

#ifndef _TEXTEDIT_H_
#define _TEXTEDIT_H_

#include "TextElement.h"
#include <string>

class TextEdit : public TextElement {
	public:
		TextEdit(int x, int y, int width, int height, string txt);
		void keyDown(int c);
		void mouseDown(int x, int y);

	private:
		void backspace();
		bool _inside;
};
#endif
