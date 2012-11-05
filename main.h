#ifndef _MAIN_H_
#define _MAIN_H_
#include "element/Element.h"

using namespace std;

void shutDown(int returnCode);
void init(void);
void mainLoop(void);
void draw(void);
void GLFWCALL windowResize( int width, int height );
int loadGuiTexture( string texture );
void GLFWCALL mouseClicked(int mButton, int clicked);
void GLFWCALL mouseMoved(int x, int y);
void buttonClicked(Element* e, int, int);
void buttonClicked2(Element* e, int, int);

#endif
