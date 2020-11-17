#ifndef TEST_TEXTURE2D_H
#define TEST_TEXTURE2D_H

#include <memory>
#include <glm.hpp>
#include <vertex-array.h>
#include <index-buffer.h>
#include <shader.h>
#include <texture.h>
#include "test.h"

namespace test {

    class TestTexture2D : public Test
    {
    private:
        std::unique_ptr<VertexBuffer> vertexBuffer;
        std::unique_ptr<VertexArray> vertexArray;
        std::unique_ptr<IndexBuffer> indexBuffer;
        std::unique_ptr<Shader> shader;
        std::unique_ptr<Texture> texture;
        glm::mat4 proj;
        glm::mat4 view;
        glm::vec3 translationA;
        glm::vec3 translationB;
    public:
        TestTexture2D();
        ~TestTexture2D();

        void onUpdate(float deltaTime) override;
        void onRender() override;
        void onImGuiRender() override;
    };

}


#endif