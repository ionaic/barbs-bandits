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
INCL=-I./image/ -I./text/ -I./element/ -I./button -I./togglebutton
# include all the things
HFILES=button/Button.h image/ImageElement.h text/TextElement.h $(INCL) $(TXTINCL)

all: clean Image.o Pixel.o Text.o Element.o
	 $(CC) $(OFILES) $(HFILES) main.cpp -o $(TARGET) $(DEMOINCL) 

debug: Image.o Pixel.o Text.o Element.o
	 $(CC) $(OFILES) $(HFILES) main.cpp -o $(TARGET) $(DEMOINCL) -g

Image.o: 
	$(CC) image/Image.cpp -c

Pixel.o:
	$(CC) image/Pixel.cpp -c

Text.o:
	$(CC) text/Text.cpp $(TXTINCL) -c -Iimage/

Element.o:
	$(CC) -I image/ element/Element.cpp -c

Demo:
	$(CC) Demo.cpp -o Demo $(DEMOINCL)

Button.o: Image.o Text.o
	$(CC) button/Button.h $(INCL) $(TXTINCL) -c

ToggleButton.o: Image.o Text.o
	$(CC) togglebutton/ToggleButton.h -I button/ $(INCL) $(TXTINCL) -c

clean:
	rm -f $(OFILES)
	rm -f *.gch image/*.gch text/*.gch demo/*.gch button/*.gch togglebutton/*.gch
	rm -f *.gch image/*.o text/*.o demo/*.o button/*.o togglebutton/*.o
