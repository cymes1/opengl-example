#ifndef DEBUG_MESSAGE_CONTROL_INFO_H
#define DEBUG_MESSAGE_CONTROL_INFO_H

#include "GL/glew.h"

namespace OpenGlExample::Debug
{
    struct DebugMessageControlInfo
    {
        GLenum source;
        GLenum type;
        GLenum severity;
        GLsizei count;
        GLuint* ids;
        GLboolean enabled;
    };
}

#endif
