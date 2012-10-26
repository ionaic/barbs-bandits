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
HFILES=button/Button.h

all: image text element button
	 $(CC) $(OFILES) main.cpp -o $(TARGET)

image:
	$(CC) image/Image.cpp -c
	$(CC) image/Pixel.cpp -c

text:
	$(CC) text/Text.cpp $(TXTINCL) -c

element:
	$(CC) -I image/ element/Element.cpp -c

demo:
	$(CC) Demo.cpp -o Demo $(DEMOINCL)

button: image text
	$(CC) button/Button.h $(INCL) $(TXTINCL) -c

togglebutton: image text
	$(CC) togglebutton/ToggleButton.h -I button/ $(INCL) $(TXTINCL) -c

debug: image text element
	$(CC) $(OFILES) main.cpp -o -g $(TARGET)

clean:
	rm $(OFILES)
	rm *.gch image/*.gch text/*.gch demo/*.gch button/*.gch togglebutton/*.gch
