#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include "utils.h"
#include "vertex-array.h"
#include "index-buffer.h"
#include "shader.h"

class Renderer
{
public:
    void clear() const;
    void draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const;
};

#endif