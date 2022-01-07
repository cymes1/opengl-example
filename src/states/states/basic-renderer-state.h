#ifndef BASIC_RENDERER_STATE_H
#define BASIC_RENDERER_STATE_H

#include <states/states/base/state.h>
#include <renderer/basic-renderer.h>
#include <renderer/sprite.h>

namespace OpenGlExample::States
{
	class BasicRendererState : public State
	{
	private:
		Renderer::BasicRenderer renderer;
		Renderer::Sprite spriteA;
		Renderer::Sprite spriteB;

	public:
		explicit BasicRendererState(Root& root);

		void render() override;
		void renderImGui() override;
	};
}


#endif