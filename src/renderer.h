#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <GL/glew.h>

#define GLCall(x)   \
    clearGLError(); \
    x;              \
    logGLCall(#x, __FILE__, __LINE__)

void clearGLError();
bool logGLCall(const char* function, const char* file, int line);

#endif