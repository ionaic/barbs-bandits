all: element image
	g++ -I ../image/ Image.o Pixel.o element.o main.cpp -o element
    
element:
	g++ -c -I ../image/ element.cpp

image:
	g++ -c ../image/Image.cpp ../image/Pixel.cpp

clean:
	rm Image.o element.o Pixel.o
