all: element image
	g++ -I ../image/ Image.o Pixel.o Element.o Main.cpp -o Element
    
element:
	g++ -c -I ../image/ Element.cpp

image:
	g++ -c ../image/Image.cpp ../image/Pixel.cpp

clean:
	rm Image.o Element.o Pixel.o
