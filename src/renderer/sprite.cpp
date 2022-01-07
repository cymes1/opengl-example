#include "sprite.h"
#include <GL/glew.h>

namespace OpenGlExample::Renderer
{
	Sprite::Sprite(const char* filepath, float width, float height)
	{
		float halfWidth = width / 2.0f;
		float halfHeight = height / 2.0f;
		positions[0]  = -halfWidth;
		positions[1]  = -halfHeight;
		positions[2]  =  0.0f;
		positions[3]  =  0.0f;
		positions[4]  =  halfWidth;
		positions[5]  = -halfHeight;
		positions[6]  =  1.0f;
		positions[7]  =  0.0f;
		positions[8]  =  halfWidth;
		positions[9]  =  halfHeight;
		positions[10] =  1.0f;
		positions[11] =  1.0f;
		positions[12] = -halfWidth;
		positions[13] =  halfHeight;
		positions[14] =  0.0f;
		positions[15] =  1.0f;

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, 4 * 4 * sizeof(float), positions, GL_STATIC_DRAW);

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		GLsizei stride = 4 * 4;
		GLuint offset = 0;
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, false, stride, reinterpret_cast<const void*>(offset));
		offset += 2 * 4;
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, false, stride, reinterpret_cast<const void*>(offset));

		texture = new Texture(filepath);
	}

	Sprite::~Sprite()
	{
		texture->unbind();
		delete texture;
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
	}

	glm::vec3 Sprite::getPosition() const
	{
		return position;
	}

	void Sprite::setPosition(glm::vec3 value)
	{
		position = value;
	}

	glm::vec3 Sprite::getScale() const
	{
		return scale;
	}

	void Sprite::setScale(glm::vec3 value)
	{
		scale = value;
	}

	void Sprite::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindVertexArray(vao);
		texture->bind();
	}
}