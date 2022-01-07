#include "basic-renderer-state.h"
#include "vec3.hpp"
#include <GL/glew.h>
#include <imgui.h>
#include <states/states/menu-state.h>

namespace OpenGlExample::States
{
	BasicRendererState::BasicRendererState(Root &root)
		: State(root),
		  spriteA("res/texture/test-texture.png", 100, 100),
		  spriteB("res/texture/test-texture.png", 100, 100)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		spriteA.setPosition(glm::vec3(200, 200, 0));
		spriteA.setScale(glm::vec3(1, 1, 1));
		spriteB.setPosition(glm::vec3(400, 200, 0));
		spriteB.setScale(glm::vec3(1, 1, 1));
	}

	void BasicRendererState::render()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		renderer.draw(spriteA);
		renderer.draw(spriteB);
	}

	void BasicRendererState::renderImGui()
	{
		ImGui::Begin("Texture 2D");
		if(ImGui::Button("<-"))
		{
			root.createState<MenuState>();
		}

		glm::vec3 value = spriteA.getPosition();
		ImGui::SliderFloat3("position A", &value.x, 0.0f, 960.0f);
		spriteA.setPosition(value);
		value = spriteA.getScale();
		ImGui::SliderFloat3("Scale A", &value.x, 0.1f, 3.0f);
		spriteA.setScale(value);

		value = spriteB.getPosition();
		ImGui::SliderFloat3("position B", &value.x, 0.0f, 960.0f);
		spriteB.setPosition(value);
		value = spriteB.getScale();
		ImGui::SliderFloat3("Scale B", &value.x, 0.1f, 3.0f);
		spriteB.setScale(value);
	}
}