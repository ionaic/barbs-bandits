//http://web.engr.oregonstate.edu/~mjb/cs553/Handouts/Texture/texture.pdf
#include <GL/glfw.h>
//#include <FreeImage.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "main.h"
#include "Element.h"
#include "ImageElement.h"

using namespace std;

static bool running = GL_TRUE;
static int vsync = 1;
static float aspectRatio = 0;
GLuint texture;
static string textureFile = "texture.bmp";

int main() {
	init();
	loadGuiTexture(textureFile);
	cout << "3" << endl;
	mainLoop();
	//shutDown(EXIT_SUCCESS);
}

int loadGuiTexture(string textureString) {
	//FreeImage_Initialise();
	//FIBITMAP *bitmap = FreeImage_Load(FIF_BMP, textureString.c_str(), BMP_DEFAULT);
	//if (!bitmap) {
	//	cout << "Texture failed to load" << endl;
	//	return 1;
	//}
	//here's the openGUI
	Pixel P(255,0,0,255);
	Image I(256, 256, P);
	ImageElement ie(0, 0, 256, 256, &I);
	Pixel* bits = I.getPixels();// ie.render()->getPixels();
	if(!bits) {
		cout << "Element texture failed to load" << endl;
		return 1;
	}
	unsigned int width = 256;
	unsigned int height = 256;

	//back to real stuff
	//int width = FreeImage_GetWidth(bitmap);
	//int height = FreeImage_GetHeight(bitmap);
	//BYTE* bits = FreeImage_GetBits(bitmap);
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
	cout << "1" << endl;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
			0, GL_RGBA, GL_UNSIGNED_BYTE, bits);
	cout << "2" << endl;
	//unload the bitmap since we're done with it
	//FreeImage_Unload(bitmap);
	return 0;
}

void shutDown(int returnCode) {
	/** shuts down glfw and exits the program with a return code
	 */

	glfwTerminate();
	//FreeImage_DeInitialise();
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

	//vsync
	glfwSwapInterval(vsync);

	//enable alpha blending
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
		draw();
		glfwSwapBuffers();
	}
}


void draw(void)
{
    // draw GUI box
	//enable texturing
	glEnable( GL_TEXTURE_2D );
    glLoadIdentity();
    glBegin(GL_QUADS);
    {
        glTexCoord2f( 0.0f, 0.0f);
        glVertex2i(-1, -1);
        glTexCoord2f( 1.0f, 0.0f);
        glVertex2i(-1, 1);
        glTexCoord2f(1.0f, 1.0f);
        glVertex2i(1, 1);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2i(1, -1);
    }
    glEnd();
    glDisable( GL_TEXTURE_2D );
}


// Callback for when the window is resized
void GLFWCALL windowResize( int width, int height ) {
	glViewport(0,0,(GLsizei)width,(GLsizei)height);

}
