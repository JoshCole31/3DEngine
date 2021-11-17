#pragma once
#include "Component.h"

namespace jc
{
	class Renderer;
	class GraphicsComponent : public Component
	{
	public:
		virtual void Draw(Renderer* renderer) = 0;
	};
}