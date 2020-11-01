#ifndef BUFFER_LAYOUT_H
#define BUFFER_LAYOUT_H

#include <vector>
#include <GL/glew.h>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_UNSIGNED_BYTE:
                return 1;
            case GL_FLOAT:
            case GL_UNSIGNED_INT:
                return 4;
            default:
                return 0;
        }
    }
};

class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> elements;
    unsigned int stride;

public:
    VertexBufferLayout();

    inline const std::vector<VertexBufferElement> getElements() const { return elements; }
    inline unsigned int getStride() const { return stride; }

    template<typename T>
    void push(unsigned int count)
    {}
};

#endif