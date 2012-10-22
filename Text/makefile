all:
	g++ -c Text.h `freetype-config --cflags` -lfreetype
	g++ -o main main.cpp Text.cpp `freetype-config --cflags` -lfreetype

debug:
	g++ -c Text.h `freetype-config --cflags` -lfreetype -g
	g++ -o main main.cpp Text.cpp `freetype-config --cflags` -lfreetype -g

clean:
	rm *.h.gch

