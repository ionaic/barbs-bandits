//http://web.engr.oregonstate.edu/~mjb/cs553/Handouts/Texture/texture.pdf
#include <GL/glfw.h>
#include <FreeImage.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include "main.h"
#include "element/Element.h"
#include "text/TextElement.h"
#include "image/ImageElement.h"
#include "togglebutton/ToggleButton.h"
#include "counter/AbstractCounter.h"
#include "counter/NumericCounter.h"
#include "counter/ProgressBar.h"
#include "button/Button.h"
#include "checkbox/CheckBox.h"

using namespace std;


static bool running = GL_TRUE;
static int vsync = 1;
static float aspectRatio = 0;
GLuint texture;
static string textureFile = "texture.bmp";
static ImageElement* ie;
static ToggleButton* TB;
static ToggleButton* TB2;
static NumericCounter* N;
static ProgressBar* PB;
static int width;
static int height;
static int WINDOW_WIDTH;
static int WINDOW_HEIGHT;

int main() {
	init();
	loadGuiTexture(textureFile);
	mainLoop();
	shutDown(EXIT_SUCCESS);
}

int loadGuiTexture(string textureString) {
	FreeImage_Initialise();
	FIBITMAP *bitmap = FreeImage_Load(FIF_BMP, textureString.c_str(), BMP_DEFAULT);
	FIBITMAP* bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
	if (!bitmap || !bitmap32) {
		cout << "Texture failed to load" << endl;
		return 1;
	}
	width = FreeImage_GetWidth(bitmap32);
	height = FreeImage_GetHeight(bitmap32);
	BYTE* texturebits = FreeImage_GetBits(bitmap32);

	//For texture
	Pixel p(255, 255, 255, 255);
	Image i(width, height, p);
	//base background element
	ie = new ImageElement(0, 0, width, height, i);
	//numeric counter next to button (bottom left)
	N = new NumericCounter(50, 0, 50, 25, 1);
	ie->addChild(N);
	//progressbar in the upper left
	PB = new ProgressBar(0, 230, 205, 25, 0);
	ie->addChild(PB);
    //lower left button
	Button* B = new Button(0, 0, 50, 20, "Button");
	B->registerMouseDownCallback( buttonClicked2 );
	ie->addChild(B);
	//toggle button on the right
	TB = new ToggleButton(206, 0, 50, 20, "Increase");
	TB->registerMouseDownCallback( buttonClicked );
	ie->addChild(TB);
	//another toggle button on the right
	TB2 = new ToggleButton(206, 50, 50, 20, "Decrease");
	TB2->registerMouseDownCallback( buttonClicked );
	ie->addChild(TB2);
	//CheckBox array
	vector <string> buttonList;
	buttonList.push_back("CB 1");
    buttonList.push_back("CB 2");
    buttonList.push_back("CB 3");
    //buttonList.push_back("CB 4");
    CheckBox* CB = new CheckBox(206, 156, 50, 100, buttonList);
    ie->addChild(CB);

	//render it to a texture by calling render
	Pixel* bits = ie->render()->getPixels();

	if(!bits) {
		cout << "Element texture failed to load" << endl;
		return 1;
	}

	//back to real stuff
	//generate and bind the texture
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	//set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//set texture clamping
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	//set lighting properties (ignore lighting for gui)
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
	//use opengl to produce the texture
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height,
			0, GL_RGBA, GL_UNSIGNED_BYTE, bits);
	//unload the bitmap since we're done with it
	FreeImage_Unload(bitmap);
	return 0;
}

void shutDown(int returnCode) {
	/** shuts down glfw and exits the program with a return code
	 */

	glfwTerminate();
	FreeImage_DeInitialise();
	exit(returnCode);
}

int closeWindow(void) {
	shutDown(EXIT_SUCCESS);
	return GL_TRUE;
}

void init(void) {
	/** Initializes a glfw window for use in the demo
	 */
	int windowWidth = 512;
	int windowHeight = 512;

	if ( GL_TRUE != glfwInit()) {
		cout << "glfw could not be initialized." << endl;
		shutDown(1);
	}

	if ( GL_TRUE != glfwOpenWindow(windowWidth, windowHeight, 8, 8, 8,
	                     8, 8, 0, GLFW_WINDOW) ) {
		shutDown(1);
	}

	//glfw stuff
	glfwSetWindowTitle("OpenGUI Demo");
	glfwSetWindowCloseCallback(closeWindow);
	glfwSetWindowSizeCallback( windowResize );
	glfwSetMouseButtonCallback( mouseClicked );
	glfwSetMousePosCallback( mouseMoved );
    //vsync
	glfwSwapInterval(vsync);

	//set clear color to white
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	//set the matrices
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	aspectRatio = ((float) windowHeight) / windowWidth;
	//glFrustum(.5, -.5, -.5 * aspectRatio, .5 * aspectRatio, 0.0, 50.0);
	glFrustum(.5, -.5, -.5, .5, 0.0, 50.0);
	glMatrixMode(GL_MODELVIEW);

}


void mainLoop(void) {
	/** the main event loop for the demo
	 */
	double oldTime = glfwGetTime();

	while(running) {
		double currentTime = glfwGetTime();
		if (glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS)
			break;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if ( currentTime > oldTime + 0.02 )
		{
		    if ( TB->isDown() ) { (*N)++; (*PB)++; }
		    if ( TB2->isDown() ) { (*N)--; (*PB)--; }
			draw();
			glfwSwapBuffers();
			oldTime = currentTime;
		}
		else
			usleep(10);
	}
}


void draw(void)
{
    // draw GUI box
	//enable texturing

    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height,
                0, GL_RGBA, GL_UNSIGNED_BYTE, ie->render()->getPixels());

	glEnable( GL_TEXTURE_2D );
    glLoadIdentity();
    glBegin(GL_QUADS);
    {

    	glTexCoord2f( 0.0f, 0.0f);
        glVertex2i(-1, -1);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2i(-1, 1);
        glTexCoord2f(1.0f, 1.0f);
        glVertex2i(1, 1);
        glTexCoord2f( 1.0f, 0.0f);
        glVertex2i(1, -1);
    }
    glEnd();
    glDisable( GL_TEXTURE_2D );
}


// Callback for when the window is resized
void GLFWCALL windowResize( int width, int height ) {
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	WINDOW_WIDTH = width;
	WINDOW_HEIGHT = height;

}

void GLFWCALL mouseClicked(int mButton, int clicked)
{
	int x, y;
	glfwGetMousePos( &x, &y );
    float I = ((float)x)/((float)WINDOW_WIDTH);
    float J = ((float)(WINDOW_HEIGHT-y))/((float)WINDOW_HEIGHT);
	if (mButton == 0 && clicked == 1) {
		ie->mouseDown(width*I, height*J);
	}
    if (mButton == 0 && clicked == 0) {
        ie->mouseUp(width*I, height*J);
    }
}

void GLFWCALL mouseMoved(int x, int y) {
    static int oldx = 0;
    static int oldy = 0;
    static bool first = true;
    y = (WINDOW_HEIGHT-y);
    if (first) {
        first = false;
        oldx = x;
        oldy = y;
    } else {
        ie->mouseMove(x,y,x-oldx,y-oldy);
        oldx = x;
        oldy = y;
    }
}

void buttonClicked(Element* e, int, int) {
	Element* element = e;
}

void buttonClicked2(Element* e, int, int) {
    Element* element = e;
    PB->setValue(0);
}
