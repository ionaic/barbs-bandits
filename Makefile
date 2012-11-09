# flags for the demo to look in (freeimage, opengl...)
DEMOINCL=-I/usr/include/ -I/usr/lib/ -L/usr/lib -lglfw -lGL -lX11 -lGLEW -lfreeimage -lGLU
# text include flags
TXTINCL=`freetype-config --cflags` -lfreetype
# compiler
CC=g++
# object files
<<<<<<< HEAD
OFILES=Image.o Pixel.o Text.o Element.o TextElement.o Button.o TextEdit.o ToggleButton.o NumericCounter.o AbstractCounter.o FractionalCounter.o ProgressBar.o BoundedCounter.o CheckBox.o RadioButton.o 
=======
OFILES=Image.o Pixel.o Text.o Element.o TextElement.o Button.o ToggleButton.o NumericCounter.o AbstractCounter.o FractionalCounter.o ProgressBar.o BoundedCounter.o CheckBox.o RadioButton.o SliderBar.o
>>>>>>> 03b4919588bfedb00f374e8a0359753265bd8e67
# final target
TARGET=sample
# generic element includes
INCL=-I./image/ -I./text/ -I./element/ -I./button -I./togglebutton -I./counter -I./checkbox
# include all the things
HFILES=button/Button.h image/ImageElement.h text/TextElement.h counter/*.h checkbox/*.h $(INCL) $(TXTINCL)

<<<<<<< HEAD
all: clean Image.o Pixel.o Text.o TextElement.o Button.o ToggleButton.o TextEdit.o Counter.o CheckBox.o RadioButton.o Element.o 
	 $(CC) $(OFILES) $(HFILES) main.cpp -o $(TARGET) $(DEMOINCL) 

debug: clean Image.o Pixel.o Text.o TextElement.o Button.o ToggleButton.o TextEdit.o Counter.o CheckBox.o RadioButton.o Element.o
=======
all: clean Image.o Pixel.o Text.o TextElement.o Button.o ToggleButton.o Counter.o CheckBox.o RadioButton.o SliderBar.o Element.o
	 $(CC) $(OFILES) $(HFILES) main.cpp -o $(TARGET) $(DEMOINCL) 

debug: clean Image.o Pixel.o Text.o TextElement.o Button.o ToggleButton.o Counter.o CheckBox.o RadioButton.o SliderBar.o Element.o
>>>>>>> 03b4919588bfedb00f374e8a0359753265bd8e67
	 $(CC) $(OFILES) $(HFILES) main.cpp -o $(TARGET) $(DEMOINCL) -g

Image.o: 
	$(CC) image/Image.cpp -c

Pixel.o:
	$(CC) image/Pixel.cpp -c

Text.o:
	$(CC) text/Text.cpp $(TXTINCL) -c -Iimage/ -g

TextElement.o:
	$(CC) text/TextElement.cpp $(TXTINCL) -c

TextEdit.o:
	$(CC) text/TextEdit.cpp $(TXTINCL) -c

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
	
SliderBar.o:
	$(CC) counter/SliderBar.cpp $(INCL) $(TXTINCL) -c
	
CheckBox.o:
	$(CC) checkbox/CheckBox.cpp $(INCL) $(TXTINCL) -c
	
RadioButton.o:
	$(CC) checkbox/RadioButton.cpp $(INCL) $(TXTINCL) -c
	

clean:
	rm -f $(OFILES)
	rm -f *.gch image/*.gch text/*.gch demo/*.gch button/*.gch togglebutton/*.gch
	rm -f *.gch image/*.o text/*.o demo/*.o button/*.o togglebutton/*.o
	rm -f */*.h.gch
