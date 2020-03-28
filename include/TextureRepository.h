#pragma once
#include <string>
#include "Texture.h"
#include "SDL.h"
#include "entt.hpp"

namespace repository {
	class TextureRepository
	{
	public:
		TextureRepository(resource::TextureCache& textureCache, SDL_Renderer* renderer);

		resource::TextureHandle load(entt::hashed_string textureId, std::string path);

	private:
		std::string texturesRoot;
		resource::TextureCache& textureCache;
		SDL_Renderer* renderer;
	};
}