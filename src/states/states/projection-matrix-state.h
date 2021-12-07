#ifndef PROJECTION_MATRIX_STATE_H
#define PROJECTION_MATRIX_STATE_H

#include <memory>
#include <glm.hpp>
#include <vertex-array.h>
#include <index-buffer.h>
#include <shader.h>
#include <states/states/base/state.h>

namespace OpenGlExample::States
{
    enum ProjectionType
    {
        ORTHOGRAPHIC,
        PERSPECTIVE
    };

    class ProjectionMatrixState : public State
    {
    private:
        std::unique_ptr<VertexBuffer> vertexBuffer;
        std::unique_ptr<VertexArray> vertexArray;
        std::unique_ptr<IndexBuffer> indexBuffer;
        std::unique_ptr<Shader> shader;
        glm::mat4 proj;
        glm::vec3 redSquarePosition;
        glm::vec3 greenSquarePosition;
        float left;
        float right;
        float bottom;
        float top;
        float near;
        float far;
        float fovy;
        glm::vec3 vecView;
        glm::vec3 vecCenter;
        glm::vec3 vecHead;
        ProjectionType projectionType;

    public:
        explicit ProjectionMatrixState(Root& root);
        ~ProjectionMatrixState() override;

        void render() override;
        void renderImGui() override;

    private:
        void renderViewportData();
        void renderElementsData();
    };
}

#endif
