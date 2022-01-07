#ifndef BASIC_RENDERER_H
#define BASIC_RENDERER_H

#include <GL/glew.h>
#include <glm.hpp>
#include <shader.h>
#include "sprite.h"

namespace OpenGlExample::Renderer
{
	class BasicRenderer
	{
	private:
		glm::mat4 proj;
		glm::mat4 view;
		unsigned int ibo;
		Shader shader;

	public:
		explicit BasicRenderer();
		~BasicRenderer();

		void draw(const Sprite& sprite);

	private:
		void createIndexBuffer();
		void compileShaders();
	};
}

#endif