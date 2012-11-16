#ifndef _OGHELPER_H_
#define _OGHELPER_H_

#include "Element.h"
#include "ImageElement.h"
#include <GL/glfw.h>
#include <string>

typedef void(*AnimCallback_t)(); /*! < TypeDef for the animation callback type */

/*! \brief Initializes the OpenGUI helper class and sets up OpenGL code to demonstrate the library
 * \param width - window width
 * \param height - window height
 * \param title - window title
 * \param baseTexture - texture to be used for the background of the GUI
 * \return returns the base element so that items can be added to it.
 */
Element * OG_init(int width, int height, string title, string baseTexture); /*! /initializes OpenGUI and returns a pointer to the background element */
/*! \brief starts the openGL event loop, causing the GUI to be rendered to the texture and displayed in the window */
void OG_run();
/*! \brief allows the user to register an animation to be run in the openGL event loop */
void OG_registerAnimation(AnimCallback_t func);

#endif
