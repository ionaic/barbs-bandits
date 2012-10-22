#ifndef __resman_h__
#define __resman_h__

class ResourceManager {
private:
	static unsigned int GPUMemoryScheme;
	static unsigned int GPUTotalMemory;
	static unsigned int TexMemory, TexMemoryLow;
	static void updateMemoryStats();
public:
	static void init();
	static void denit();
	static void update();
};

#endif
