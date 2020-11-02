#include "utils.h"

void clearGLError()
{
    while(glGetError() != GL_NO_ERROR)
    {}
}

bool logGLCall(const char* function, const char* file, int line)
{
    while(GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error]: (" << error << ") " << function <<
                  " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}
