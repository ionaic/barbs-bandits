all:
	g++ -c Button.h ../image/Pixel.h ../image/Image.h ../text/Text.h `freetype-config --cflags` -lfreetype
	g++ -o main main.cpp Button.cpp ../text/Text.cpp ../image/Pixel.cpp ../image/Image.cpp `freetype-config --cflags` -lfreetype

debug:
	g++ -c Button.h ../image/Pixel.h ../image/Image.h ../text/Text.h `freetype-config --cflags` -lfreetype -g
	g++ -o main main.cpp Button.cpp ../text/Text.cpp ../image/Pixel.cpp ../image/Image.cpp `freetype-config --cflags` -lfreetype -g

clean:
	rm *.h.gch
	rm *.o

