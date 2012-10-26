all:
	g++ -c ToggleButton.h ../image/Pixel.h ../image/Image.h ../text/Text.h `freetype-config --cflags` -lfreetype
	g++ -o Main Main.cpp ToggleButton.cpp ../text/Text.cpp ../image/Pixel.cpp ../image/Image.cpp `freetype-config --cflags` -lfreetype

debug:
	g++ -c ToggleButton.h ../image/Pixel.h ../image/Image.h ../text/Text.h `freetype-config --cflags` -lfreetype -g
	g++ -o Main Main.cpp ToggleButton.cpp ../text/Text.cpp ../image/Pixel.cpp ../image/Image.cpp `freetype-config --cflags` -lfreetype -g

clean:
	rm *.gch
	rm *.o

