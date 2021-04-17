#include "debug-callback.h"
#include <iostream>

namespace OpenGlExample::Debug
{
    void initializeDebugMode(const DebugMessageControlInfo& messageControlInfo)
    {
        glDebugMessageCallback(onOpenGlDebugMessage, nullptr);
        glDebugMessageControl(messageControlInfo.source,
                              messageControlInfo.type,
                              messageControlInfo.severity,
                              messageControlInfo.count,
                              messageControlInfo.ids,
                              messageControlInfo.enabled);
    }

    static const char* parseSeverityEnumToText(GLenum severity)
    {
        switch (severity)
        {
            case GL_DEBUG_SEVERITY_HIGH:
                return "GL_DEBUG_SEVERITY_HIGH";
            case GL_DEBUG_SEVERITY_MEDIUM:
                return "GL_DEBUG_SEVERITY_MEDIUM";
            case GL_DEBUG_SEVERITY_LOW:
                return "GL_DEBUG_SEVERITY_LOW";
            case GL_DEBUG_SEVERITY_NOTIFICATION:
                return "GL_DEBUG_SEVERITY_NOTIFICATION";
            default:
                return "unknown severity";
        }
    }

    static const char* parseTypeEnumToText(GLenum type)
    {
        switch (type)
        {
            case GL_DEBUG_TYPE_ERROR:
                return "GL_DEBUG_TYPE_ERROR";
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
                return "GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR";
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
                return "GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR";
            case GL_DEBUG_TYPE_PORTABILITY:
                return "GL_DEBUG_TYPE_PORTABILITY";
            case GL_DEBUG_TYPE_PERFORMANCE:
                return "GL_DEBUG_TYPE_PERFORMANCE";
            case GL_DEBUG_TYPE_MARKER:
                return "GL_DEBUG_TYPE_MARKER";
            case GL_DEBUG_TYPE_PUSH_GROUP:
                return "GL_DEBUG_TYPE_PUSH_GROUP";
            case GL_DEBUG_TYPE_POP_GROUP:
                return "GL_DEBUG_TYPE_POP_GROUP";
            case GL_DEBUG_TYPE_OTHER:
                return "GL_DEBUG_TYPE_OTHER";
            default:
                return "unknown type";
        }
    }

    static const char* parseSourceEnumToText(GLenum source)
    {
        switch (source)
        {
            case GL_DEBUG_SOURCE_API:
                return "GL_DEBUG_SOURCE_API";
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
                return "GL_DEBUG_SOURCE_WINDOW_SYSTEM";
            case GL_DEBUG_SOURCE_SHADER_COMPILER:
                return "GL_DEBUG_SOURCE_SHADER_COMPILER";
            case GL_DEBUG_SOURCE_THIRD_PARTY:
                return "GL_DEBUG_SOURCE_THIRD_PARTY";
            case GL_DEBUG_SOURCE_APPLICATION:
                return "GL_DEBUG_SOURCE_APPLICATION";
            case GL_DEBUG_SOURCE_OTHER:
                return "GL_DEBUG_SOURCE_OTHER";
            default:
                return "unknown source";
        }
    }

    static void logOpenGlMessage(GLuint id,
                                 const GLchar* message,
                                 const char* severity,
                                 const char* type,
                                 const char* source)
    {
        std::cout << "---------------" << std::endl;
        std::cout << "Severity: " << severity << std::endl;
        std::cout << "Debug message (" << id << "): " <<  message << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Source: " << source << std::endl;
        std::cout << std::endl << std::endl;
    }

    void APIENTRY onOpenGlDebugMessage(GLenum source,
                                      GLenum type,
                                      GLuint id,
                                      GLenum severity,
                                      GLsizei length,
                                      const GLchar* message,
                                      const void* userParam)
    {
        const char* severityText = parseSeverityEnumToText(severity);
        const char* typeText = parseTypeEnumToText(type);
        const char* sourceText = parseSourceEnumToText(source);
        logOpenGlMessage(id, message, severityText, typeText, sourceText);
    }
}