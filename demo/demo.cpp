#include <GL/glfw.h>
#include "demo.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

static bool running = GL_TRUE;
static int vsync = 1;
static float aspectRatio = 0;

int main() {
	init();
	mainLoop();
	shutDown(EXIT_SUCCESS);
}

void shutDown(int returnCode) {
	/** shuts down glfw and exits the program with a return code
	 */

	glfwTerminate();
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
	glEnable(GL_BLEND);
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
    glLoadIdentity();
    glBegin(GL_QUADS);
    {
        glColor4f(0.8, 0.4, 0.4, 0.5);
        glVertex2f( .98,  .98 );//* aspectRatio);
        glVertex2f(-.98,  .98 );//* aspectRatio);
        glVertex2f(-.98, -.98 );//* aspectRatio);
        glVertex2f( .98, -.98 );//* aspectRatio);
    }
    glEnd();
}


// Callback for when the window is resized
void GLFWCALL windowResize( int width, int height ) {
	glViewport(0,0,(GLsizei)width,(GLsizei)height);

}
