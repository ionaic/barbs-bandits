# flags for the demo to look in (freeimage, opengl...)
DEMOINCL=-I/usr/include/ -I/usr/lib/ -L/usr/lib -lglfw -lGL -lX11 -lGLEW -lfreeimage -lGLU
# text include flags
TXTINCL=`freetype-config --cflags` -lfreetype
# compiler
CC=g++
# object files
OFILES=Image.o Pixel.o Text.o Element.o TextElement.o Button.o ToggleButton.o NumericCounter.o AbstractCounter.o FractionalCounter.o ProgressBar.o BoundedCounter.o
# final target
TARGET=sample
# generic element includes
INCL=-I./image/ -I./text/ -I./element/ -I./button -I./togglebutton -I./counter
# include all the things
HFILES=button/Button.h image/ImageElement.h text/TextElement.h counter/*.h $(INCL) $(TXTINCL)

all: clean Image.o Pixel.o Text.o TextElement.o Button.o ToggleButton.o Counter.o Element.o 
	 $(CC) $(OFILES) $(HFILES) main.cpp -o $(TARGET) $(DEMOINCL) 

debug: clean Image.o Pixel.o Text.o TextElement.o Button.o ToggleButton.o Counter.o Element.o
	 $(CC) $(OFILES) $(HFILES) main.cpp -o $(TARGET) $(DEMOINCL) -g

Image.o: 
	$(CC) image/Image.cpp -c

Pixel.o:
	$(CC) image/Pixel.cpp -c

Text.o:
	$(CC) text/Text.cpp $(TXTINCL) -c -Iimage/ -g

TextElement.o:
	$(CC) text/TextElement.cpp $(TXTINCL) -c

Element.o:
	$(CC) -I image/ element/Element.cpp -c

Button.o: Image.o Text.o
	$(CC) button/Button.cpp $(INCL) $(TXTINCL) -c

ToggleButton.o: Image.o Text.o
	$(CC) togglebutton/ToggleButton.cpp -I button/ $(INCL) $(TXTINCL) -c

Counter.o: Image.o Text.o
	$(CC) counter/AbstractCounter.cpp $(INCL) $(TXTINCL) -c
	$(CC) counter/NumericCounter.cpp $(INCL) $(TXTINCL) -c
	$(CC) counter/BoundedCounter.cpp $(INCL) $(TXTINCL) -c
	$(CC) counter/FractionalCounter.cpp $(INCL) $(TXTINCL) -c
	$(CC) counter/ProgressBar.cpp $(INCL) $(TXTINCL) -c
	$(CC) counter/SliderBar.h $(INCL) $(TXTINCL) -c

clean:
	rm -f $(OFILES)
	rm -f *.gch image/*.gch text/*.gch demo/*.gch button/*.gch togglebutton/*.gch
	rm -f *.gch image/*.o text/*.o demo/*.o button/*.o togglebutton/*.o
	rm -f */*.h.gch
