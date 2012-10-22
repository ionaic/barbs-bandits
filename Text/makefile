all:
	g++ -c Text.h ../image/Pixel.h ../image/Image.h `freetype-config --cflags` -lfreetype
	g++ -o main main.cpp Text.cpp ../image/Pixel.cpp ../image/Image.cpp `freetype-config --cflags` -lfreetype

debug:
	g++ -c Text.h ../image/Pixel.h ../image/Image.h `freetype-config --cflags` -lfreetype -g
	g++ -o main main.cpp Text.cpp ../image/Pixel.cpp ../image/Image.cpp `freetype-config --cflags` -lfreetype -g

clean:
	rm *.h.gch

