// include GLEW to access OpenGL 3.3 functions
#include <GL/glew.h>
#include <iostream>
#include "resman.h"

void ResourceManager::init() {
	if (glewIsSupported("GL_NVX_gpu_memory_info")) {
		std::cout<<"supported"<<std::endl;
	}
}

void ResourceManager::denit() {
	
}