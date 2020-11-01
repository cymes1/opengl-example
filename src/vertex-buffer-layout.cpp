#include "vertex-buffer-layout.h"

VertexBufferLayout::VertexBufferLayout()
        : stride(0)
{}

template<>
void VertexBufferLayout::push<float>(unsigned int count)
{
    elements.push_back({GL_FLOAT, count, false});
    stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
}

template<>
void VertexBufferLayout::push<unsigned int>(unsigned int count)
{
    elements.push_back({GL_UNSIGNED_INT, count, false});
    stride += sizeof(GLuint);
    stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
}

template<>
void VertexBufferLayout::push<unsigned char>(unsigned int count)
{
    elements.push_back({GL_UNSIGNED_BYTE, count, false});
    stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
}