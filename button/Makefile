all: image font button element
	g++ -o main main.cpp Pixel.o Image.o Text.o Button.o

button: 
	g++ -c Button.h -I../image/ -I../text/ -I../element/ `freetype-config --cflags` -lfreetype

image:
	g++ -c ../image/Pixel.cpp ../image/Image.cpp

element:
	g++ -c ../image/Element.cpp

font:
	g++ -c ../text/Text.cpp `freetype-config --cflags` -lfreetype

debug: image font button element
	g++ -c Button.h -I../image/ -I../text/ `freetype-config --cflags` -lfreetype

clean:
	rm *.h.gch
	rm *.o
