#include <string>
#include "../image/Image.h"
#include "../text/Text.h"
#include "../element/Element.h"
#include "../image/ImageElement.h"
#include "../text/TextElement.h"

class Dimension {
	public: unsigned int value;
};

class Coordinate {
	public: unsigned int value;
};

class TextValue {
	public: string text;
}

/*!Constructor sets x,y position, width and heigh according to arguments. Leaves text empty */
class Button {
	public:
	Button(Coordinate x, Coordinate y, Dimension width, Dimension height): Element(x, y, width, height) {
		Pixel p(255, 255, 255, 127);
		Image i(width, height, p);
		_imageElement = new ImageElement(0, 0, width, height, i); //need to draw image first
		setBgIg(_imageElement);
		_textElement = new TextElement(0, 0, width, height, 0, "");
		addChild(_textElement);
	}

	/*!Constructor sets x,y, width, height and text */
	Button(Coordinate x, Coordinate y, Dimension width, Dimension height, TextValue text) : Element(x, y, width, height) {
		Pixel p(255, 255, 255, 127);
		Image i(width, height, p);
		_imageElement = new ImageElement(0, 0, width, height, i); //need to draw image first
		setBgIg(_imageElement);
		_textElement = new TextElement(0, 0, width, height, 0, text);
		addChild(_textElement);
	}

	/*!Constructor sets x,y, width height and a background of an image */
	Button(Coordinate x, Coordinate y, Dimension width, Dimension height, ImageElement* image) : Element(x, y, width, height) {
		setBgIg(image);
		_textElement = new TextElement(0, 0, width, height);
		addChild(_textElement);
	}

	/*!Sets the background image of a button*/
	void setBgIg(ImageElement* image) {
		_imageElement = image;		//need to draw image first
		image->setZ(-1);
		Element::addChild(image);
		setDirty(true);
		image->setDirty(true);
	}

	/*!Sets the text of a button*/
	void setText(TextValue text) {
		_textElement->setText(text);
		_textElement->setDirty(true);
	}

	protected:
		TextElement* _textElement;
	    ImageElement* _imageElement;
}
