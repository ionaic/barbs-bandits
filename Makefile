all: image text element
	 g++ Image.o Pixel.o Text.o Element.o Button.o ToggleButton.o main.cpp -o sample

image:
	g++ -c image/Image.cpp image/Pixel.cpp

text:
	g++ -c ../text/Text.cpp `freetype-config --cflags` -lfreetype

element:
	g++ -c -I./image/ element/Element.cpp

demo:
	g++ Demo.cpp -o Demo -I/usr/include/ -I/usr/lib/ -L/usr/lib -lglfw -lGL -lX11 -lGLEW -lfreeimage -lGLU

button: image text
	g++ -c Button.h -I../image/ -I../text/ -I../element/ `freetype-config --cflags` -lfreetype

togglebutton: image text
	g++ -c Button.h -I../image/ -I../text/ -I../element/ `freetype-config --cflags` -lfreetype

debug: image text element
	 g++ Image.o Pixel.o Text.o Element.o Button.o ToggleButton.o main.cpp -o -g sample

clean:
	rm Image.o Pixel.o Element.o
