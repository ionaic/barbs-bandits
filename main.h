#ifndef _MAIN_H_
#define _MAIN_H_

using namespace std;

void shutDown(int returnCode);
void init(void);
void mainLoop(void);
void draw(void);
void GLFWCALL windowResize( int width, int height );
int loadGuiTexture( string texture );

#endif
