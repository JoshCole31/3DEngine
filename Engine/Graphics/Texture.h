#pragma once
#include "Resource/Resource.h"
#include "MathTypes.h"
#include <SDL.h>

namespace jc
{
	
	class Texture : public Resource
	{
	public:
		Texture() {}
		Texture(class Renderer* renderer);

		bool Load(const std::string& name,void* data) override;

		glm::vec2 GetSize() const;

		friend class Renderer;
		bool Create(SDL_Surface* surface);

	private:
		SDL_Texture* texture{ nullptr };
		SDL_Renderer* renderer{ nullptr };
	};

}