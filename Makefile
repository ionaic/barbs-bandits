# flags for the demo to look in (freeimage, opengl...)
DEMOINCL=-I/usr/include/ -I/usr/lib/ -L/usr/lib -lglfw -lGL -lX11 -lGLEW -lfreeimage -lGLU
# text include flags
TXTINCL=`freetype-config --cflags` -lfreetype
# compiler
CC=g++
# object files
OFILES=Image.o Pixel.o Text.o Element.o TextElement.o Button.o TextEdit.o ToggleButton.o NumericCounter.o AbstractCounter.o FractionalCounter.o ProgressBar.o BoundedCounter.o CheckBox.o RadioButton.o SliderBar.o
# final target
TARGET=sample
# generic element includes
INCL=-I./image/ -I./text/ -I./element/ -I./button -I./togglebutton -I./counter -I./checkbox
# include all the things
HFILES=button/Button.h image/ImageElement.h text/TextElement.h counter/*.h checkbox/*.h $(INCL) $(TXTINCL)

all: $(OFILES) 
	 $(CC) $(OFILES) $(HFILES) main.cpp -o $(TARGET) $(DEMOINCL) 

lib: cleanlib OpenGUI.o
	ar rcs libOpenGUI.a OpenGUI.o
	mkdir libOpenGUI
	mkdir libOpenGUI/lib
	mv libOpenGUI.a libOpenGUI/lib/libOpenGUI.a
	mkdir libOpenGUI/include
	mkdir libOpenGUI/include/libOpenGUI
	cp togglebutton/ToggleButton.h libOpenGUI/include/libOpenGUI/ToggleButton.h
	cp image/Image.h libOpenGUI/include/libOpenGUI/Image.h
	cp image/ImageElement.h libOpenGUI/include/libOpenGUI/ImageElement.h
	cp image/Pixel.h libOpenGUI/include/libOpenGUI/Pixel.h
	cp element/Element.h libOpenGUI/include/libOpenGUI/Element.h
	cp counter/AbstractCounter.h libOpenGUI/include/libOpenGUI/AbstractCounter.h
	cp counter/BoundedCounter.h libOpenGUI/include/libOpenGUI/BoundedCounter.h
	cp counter/ProgressBar.h libOpenGUI/include/libOpenGUI/ProgressBar.h
	cp counter/NumericCounter.h libOpenGUI/include/libOpenGUI/NumericCounter.h
	cp counter/FractionalCounter.h libOpenGUI/include/libOpenGUI/FractionalCounter.h
	cp counter/SliderBar.h libOpenGUI/include/libOpenGUI/SliderBar.h
	cp checkbox/CheckBox.h libOpenGUI/include/libOpenGUI/CheckBox.h
	cp checkbox/RadioButton.h libOpenGUI/include/libOpenGUI/RadioButton.h
	cp button/Button.h libOpenGUI/include/libOpenGUI/Button.h
	cp openGUI.h libOpenGUI/include/openGUI.h

cleanlib:
	rm -f -r -d libOpenGUI	

debug: clean Image.o Pixel.o Text.o TextElement.o Button.o ToggleButton.o TextEdit.o Counter.o CheckBox.o RadioButton.o SliderBar.o Element.o
	 $(CC) $(OFILES) $(HFILES) main.cpp -o $(TARGET) $(DEMOINCL) -g

OpenGUI.o: $(OFILES)
	ld -r $(OFILES) -o "OpenGUI.o"

Image.o: Pixel.o image/Image.h 
	$(CC) image/Image.cpp -c

Pixel.o:
	$(CC) image/Pixel.cpp -c

Text.o: Image.o text/Text.h
	$(CC) text/Text.cpp $(TXTINCL) -c -Iimage/ -g

TextElement.o: Text.o text/TextElement.h
	$(CC) text/TextElement.cpp $(TXTINCL) -c

TextEdit.o: Element.o Text.o text/TextEdit.h
	$(CC) text/TextEdit.cpp $(TXTINCL) -c

Element.o: Image.o element/Element.h
	$(CC) -I image/ element/Element.cpp -c

Button.o: Element.o Text.o
	$(CC) button/Button.cpp $(INCL) $(TXTINCL) -c

ToggleButton.o: Element.o Text.o
	$(CC) togglebutton/ToggleButton.cpp -I button/ $(INCL) $(TXTINCL) -c

AbstractCounter.o: Element.o Text.o counter/AbstractCounter.h
	$(CC) counter/AbstractCounter.cpp $(INCL) $(TXTINCL) -c

NumericCounter.o: Element.o Text.o AbstractCounter.o counter/NumericCounter.h
	$(CC) counter/NumericCounter.cpp $(INCL) $(TXTINCL) -c

BoundedCounter.o: Element.o Text.o AbstractCounter.o counter/BoundedCounter.h
	$(CC) counter/BoundedCounter.cpp $(INCL) $(TXTINCL) -c

FractionalCounter.o: Element.o Text.o AbstractCounter.o counter/FractionalCounter.h
	$(CC) counter/FractionalCounter.cpp $(INCL) $(TXTINCL) -c

ProgressBar.o: Element.o AbstractCounter.o counter/ProgressBar.h
	$(CC) counter/ProgressBar.cpp $(INCL) $(TXTINCL) -c
	
SliderBar.o: Element.o AbstractCounter.o counter/SliderBar.h
	$(CC) counter/SliderBar.cpp $(INCL) $(TXTINCL) -c
	
CheckBox.o: Element.o Text.o checkbox/CheckBox.h
	$(CC) checkbox/CheckBox.cpp $(INCL) $(TXTINCL) -c
	
RadioButton.o: Element.o Text.o checkbox/RadioButton.h
	$(CC) checkbox/RadioButton.cpp $(INCL) $(TXTINCL) -c
	

clean: cleanlib
	rm -f $(OFILES)
	rm -f *.gch image/*.gch text/*.gch demo/*.gch button/*.gch togglebutton/*.gch
	rm -f *.gch image/*.o text/*.o demo/*.o button/*.o togglebutton/*.o
	rm -f */*.h.gch
