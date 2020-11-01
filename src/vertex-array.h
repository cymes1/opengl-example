#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <GL/glew.h>
#include "vertex-buffer.h"
#include "vertex-buffer-layout.h"
#include "renderer.h"

class VertexArray
{
private:
    unsigned int rendererId;
public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void bind() const;
    void unbind() const;
};

#endif