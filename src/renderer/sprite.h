#ifndef SPRITE_H
#define SPRITE_H

#include <glm.hpp>
#include "texture.h"
#include "shader.h"

namespace OpenGlExample::Renderer
{
	class Sprite
	{
	private:
		float positions[16]{};
		unsigned int vbo;
		unsigned int vao;
		unsigned int ibo;
		Texture* texture;
		glm::vec3 position;
		glm::vec3 scale;

	public:
		Sprite(const char* filepath, float width, float height);
		~Sprite();

		glm::vec3 getPosition() const;
		void setPosition(glm::vec3 value);
		glm::vec3 getScale() const;
		void setScale(glm::vec3 value);
		void bind() const;
	};
}

#endif