# flags for the demo to look in (freeimage, opengl...)
DEMOINCL=-I/usr/include/ -I/usr/lib/ -L/usr/lib -lglfw -lGL -lX11 -lGLEW -lfreeimage -lGLU
# text include flags
TXTINCL=`freetype-config --cflags` -lfreetype
# compiler
CC=g++
# object files
OFILES=image/Image.o image/Pixel.o text/Text.o element/Element.o button/Button.o togglebutton/ToggleButton.o 
# final target
TARGET=sample
# generic element includes
INCL=-I./image/ -I./text/ -I./element/ 

all: image text element button togglebutton
	 $(CC) $(OFILES) main.cpp -o $(TARGET)

image:
	$(CC) -c image/Image.cpp image/Pixel.cpp

text:
	$(CC) -c text/Text.cpp $(TXTINCL)

element:
	$(CC) -c -I image/ element/Element.cpp

demo:
	$(CC) Demo.cpp -o Demo $(DEMOINCL)

button: image text
	$(CC) -c button/Button.h $(INCL) $(TXTINCL)

togglebutton: image text
	$(CC) -c togglebutton/ToggleButton.h -I button/ $(INCL) $(TXTINCL)

debug: image text element
	$(CC) $(OFILES) main.cpp -o -g $(TARGET)

clean:
	rm $(OFILES)
	rm *.gch image/*.gch text/*.gch demo/*.gch button/*.gch togglebutton/*.gch
