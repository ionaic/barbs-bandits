#ifndef _OGHELPER_H_
#define _OGHELPER_H_

#include "Element.h"
#include "../image/ImageElement.h"
#include <GL/glfw.h>
#include <string>

Element * OG_init(int width, int height, string title, string baseTexture); /*! /initializes OpenGUI and returns a pointer to the background element */
void OG_run();
void OG_addChild(Element *);

#endif
