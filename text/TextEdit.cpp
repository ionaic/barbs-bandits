#include "TextEdit.h"
#include "TextElement.h"
#include <string>

TextEdit::TextEdit(int x, int y, int width, int height, string txt) :
	TextElement(x,y,width,height,14,txt) { }

void TextEdit::keyDown(int c) {
	if (c==-1) {
		backspace(); 
	} else {
		setText(_text->getText()+char(c));
	}
}

void TextEdit::backspace() {
	string t = _text->getText();
	if (t.length() > 0) {
		t = t.substr(0,t.length()-1);
		setText(t);
	}
}
