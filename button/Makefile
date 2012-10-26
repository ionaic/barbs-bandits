INCL=-I../image/ -I../text/ -I../element/ `freetype-config --cflags` -lfreetype

all: image font button element
	g++ $(INCL) main.cpp Pixel.o Image.o Text.o Button.h -o main

button: 
	g++ -c Button.h $(INCL)

image:
	g++ -c ../image/Pixel.cpp ../image/Image.cpp

element:
	g++ -c ../element/Element.cpp -I../image/

font:
	g++ -c ../text/Text.cpp `freetype-config --cflags` -lfreetype

debug: image font button element
	g++ -c Button.h -I../image/ -I../text/ `freetype-config --cflags` -lfreetype

clean:
	rm *.h.gch
	rm *.o
