#ifndef _OGHELPER_H_
#define _OGHELPER_H_

#include "Element.h"
#include "ImageElement.h"
#include <GL/glfw.h>
#include <string>

Element * OG_init(int width, int height, string title, string baseTexture); /*! /initializes OpenGUI and returns a pointer to the background element */
void OG_run();
void OG_addChild(Element *);
typedef void(*AnimCallback_t)();
void OG_registerAnimation(AnimCallback_t func);

#endif
