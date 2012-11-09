#ifndef _OGHELPER_H_
#define _OGHELPER_H_

#include "Element.h"
#include "../image/ImageElement.h"
#include <GL/glfw.h>
#include <string>

class OGHelper {
public:
    OGHelper(int width, int height, string title);
    ~OGHelper();
    Element * OG_init(string baseTexture); /*! /initializes OpenGUI and returns a pointer to the background element */
    void render();
    void run();
    void addChild(Element *);

private:
    void _init();
    bool _running;
    void _draw();
    string _title;
    int _windowWidth;
    int _windowHeight;
    int _textureWidth;
    int _textureHeight;
    bool _initialized;
    Element* e;
    void GLFWCALL windowResize( int width, int height );
    void GLFWCALL mouseClicked(int mButton, int clicked);
    void GLFWCALL mouseMoved(int x, int y);
    void GLFWCALL keyPressed(int key, int action);
    void GLFWCALL printableKeyPressed(int key, int action);
    int ext(int returnCode);
    GLuint texture;
    bool _quit;
};

#endif
