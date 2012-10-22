#include "libs.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "shader.h"
#include "textureLoader.h"
#include "resman/resman.h"
using std::cout; using std::endl;

// global variables to store the scene geometry
GLuint vertexArrayID;
GLuint bufferIDs[2];
// GL texture ID
GLuint TexID = 0;
// shader program
Shader shader;

// initialize the scene geometry
void initGeometry() {
	static const GLfloat rawVertexData[12] = { -1.0f,1.0f,0.0f, -1.0f,-1.0f,0.0f,  1.0f,1.0f,0.0f,  1.0f,-1.0f,0.0f };
	static const GLfloat rawTexCoordData[12] = {0.0f,1.0f,0.0f,  0.0f, 0.0f,0.0f,  1.0f,1.0f,0.0f,  1.0f,0.0f,0.0f };
	// create a new renderable object and set it to be active
	glGenVertexArrays(1,&vertexArrayID);
	glBindVertexArray(vertexArrayID);
	// create buffers for associated data
	glGenBuffers(2,bufferIDs);
	
	// set a buffer to be active and shove vertex data into it
	glBindBuffer(GL_ARRAY_BUFFER, bufferIDs[0]);
	glBufferData(GL_ARRAY_BUFFER, 12*sizeof(GLfloat), rawVertexData, GL_STATIC_DRAW);
	// bind that data to shader variable 0
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	
	// set a buffer to be active and shove color data into it
	glBindBuffer(GL_ARRAY_BUFFER, bufferIDs[1]);
	glBufferData(GL_ARRAY_BUFFER, 12*sizeof(GLfloat), rawTexCoordData, GL_STATIC_DRAW);
	// bind that data to shader variable 1
	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
}
void bindShaderAttribLocations(GLuint p) {
	// assign numerical IDs to the variables that we pass to the shaders 
	glBindAttribLocation(p,0, "in_Position");
	glBindAttribLocation(p,1, "in_ColorTexCoords");
}
void initShaders() {
	shader = Shader(ShaderCallbacks(bindShaderAttribLocations));
	if (!shader.loadShaderFiles("textured.vert","textured.frag")) {
		shader.getErrortext(cout);
		exit(1);
	}
	shader.bind();
	glUniform1i(glGetUniformLocation(shader.id(),"ColorTex"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,TexID);
}

// Callback for when the window is resized
void GLFWCALL windowResize( int width, int height ) {
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
}
int main( int argc, char ** argv ) {
	if (argc<2) {
		cout << "Please pass the path to an image file as a parameter to the program!\n";
		exit(1);
	}
	textureLoader::init();
	
	// Initialize GLFW
	if( !glfwInit() ) {
		exit( EXIT_FAILURE );
	}
	// Open an OpenGL window
	if( !glfwOpenWindow( 800,600, 0,0,0,0,0,0, GLFW_WINDOW ) ) {
		glfwTerminate();
		exit( EXIT_FAILURE );
	}
	
	glfwSetWindowTitle("OpenGL Viewer");
	glfwSetWindowSizeCallback( windowResize );
	glfwSwapInterval( 1 );
	windowResize(800,600);
	glewInit();
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);
	// load a texture
	TexID = textureLoader::loadFromFile(argv[1]);
	// last of the init
	initGeometry();
	initShaders();
	GLint texUnits;
	glGetIntegerv(GL_MAX_TEXTURE_UNITS,&texUnits);
	cout << "# of tex units: " << texUnits << endl;
	// Main loop
	int running = GL_TRUE;
	ResourceManager::init();
	while( running ) {
		// OpenGL rendering goes here...
		glClear( GL_COLOR_BUFFER_BIT );
		// draw the triangle
		glBindVertexArray(vertexArrayID);
		glDrawArrays(GL_TRIANGLE_STRIP,0,4);
		// Swap front and back rendering buffers
		glfwSwapBuffers();
		// Check if ESC key was pressed or window was closed
		running = !glfwGetKey( GLFW_KEY_ESC ) && glfwGetWindowParam( GLFW_OPENED );
	}
	textureLoader::denit();
	// delete the texture
	glDeleteTextures(1, &TexID);
	// delete the buffers
	glDeleteVertexArrays(1,&vertexArrayID);
	glDeleteBuffers(3,bufferIDs);
	// Close window and terminate GLFW
	glfwTerminate();
	// Exit program
	exit( EXIT_SUCCESS );
}
