#include "vertex-array.h"

VertexArray::VertexArray()
{
    GLCall(glGenVertexArrays(1, &rendererId));
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1, &rendererId));
}

void VertexArray::addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
{
    bind();
    vb.bind();
    const auto& elements = layout.getElements();
    unsigned int offset = 0;
    for(unsigned int i = 0; i < elements.size(); i++)
    {
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i,
                                     elements[i].count,
                                     elements[i].type,
                                     elements[i].normalized,
                                     layout.getStride(),
                                     reinterpret_cast<const void*>(offset * sizeof(unsigned int))));
        offset += elements[i].count * VertexBufferElement::getSizeOfType(elements[i].type);
    }
}

void VertexArray::bind() const
{
    GLCall(glBindVertexArray(rendererId));
}

void VertexArray::unbind() const
{
    GLCall(glBindVertexArray(0));
}