#ifndef DEBUG_CALLBACK_H
#define DEBUG_CALLBACK_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <debug/debug-message-control-info.h>

namespace OpenGlExample::Debug
{
    void initializeDebugMode(const DebugMessageControlInfo& messageControlInfo);
    void APIENTRY onOpenGlDebugMessage(GLenum source,
                                       GLenum type,
                                       GLuint id,
                                       GLenum severity,
                                       GLsizei length,
                                       const GLchar* message,
                                       const void* userParam);
}

#endif
