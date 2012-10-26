# flags for the demo to look in (freeimage, opengl...)
DEMOINCL=-I/usr/include/ -I/usr/lib/ -L/usr/lib -lglfw -lGL -lX11 -lGLEW -lfreeimage -lGLU
# text include flags
TXTINCL=`freetype-config --cflags` -lfreetype
# compiler
CC=g++
# object files
OFILES=Image.o Pixel.o Text.o Element.o
# final target
TARGET=sample
# generic element includes
INCL=-I./image/ -I./text/ -I./element/ 
# include all the things
HFILES=button/Button.h image/ImageElement.h text/TextElement.h $(INCL) $(TXTINCL)

all: Image.o Pixel.o Text.o Element.o
	 $(CC) $(OFILES) $(HFILES) $(DEMOINCL) main.cpp -o $(TARGET)

Image.o:
	$(CC) image/Image.cpp -c

Pixel.o:
	$(CC) image/Pixel.cpp -c

Text.o:
	$(CC) text/Text.cpp $(TXTINCL) -c

Element.o:
	$(CC) -I image/ element/Element.cpp -c

Demo:
	$(CC) Demo.cpp -o Demo $(DEMOINCL)

Button.o: Image.o Text.o
	$(CC) button/Button.h $(INCL) $(TXTINCL) -c

ToggleButton.o: Image.o Text.o
	$(CC) togglebutton/ToggleButton.h -I button/ $(INCL) $(TXTINCL) -c

debug: Image.o Text.o Element.o
	$(CC) $(OFILES) main.cpp -o -g $(TARGET)

clean:
	rm $(OFILES)
	rm *.gch image/*.gch text/*.gch demo/*.gch button/*.gch togglebutton/*.gch
