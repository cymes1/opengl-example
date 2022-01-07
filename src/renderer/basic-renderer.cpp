#include "basic-renderer.h"
#include <gtc/matrix_transform.hpp>

namespace OpenGlExample::Renderer
{
	BasicRenderer::BasicRenderer()
		: proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
		view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
		shader("res/shader/texture-2d/basic-texture.shader")
	{
		createIndexBuffer();
		compileShaders();
	}

	BasicRenderer::~BasicRenderer()
	{
		shader.unbind();
		glDeleteBuffers(1, &ibo);
	}

	void BasicRenderer::createIndexBuffer()
	{
		unsigned int indices[] = {
				0, 1, 2,
				2, 3, 0
		};

		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
	}

	void BasicRenderer::compileShaders()
	{
		shader.bind();
		shader.setUniform1i("u_Texture", 0);
	}

	void BasicRenderer::draw(const Sprite& sprite)
	{
		sprite.bind();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glm::mat4 model = glm::translate(glm::mat4(1.0f), sprite.getPosition());
		glm::mat4 mvp = proj * view * model;
		mvp = glm::scale(mvp, sprite.getScale());
		shader.setUniformMat4f("u_MVP", mvp);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}
}