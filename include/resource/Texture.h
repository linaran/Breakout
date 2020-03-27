#pragma once
#include <string>
#include "SDL.h"
#include "entt.hpp"

namespace resource
{
	struct Texture
	{
		Texture(SDL_Renderer* renderer, const std::string& path);

		~Texture();

		SDL_Texture* const sdlTexture;
		const int width;
		const int height;

	private:
		// Constructor helpers.
		const int queryTextureWidth();
		const int queryTextureHeight();
	};

	struct TextureLoader final : entt::resource_loader<TextureLoader, Texture>
	{
		std::shared_ptr<Texture> load(SDL_Renderer* renderer, const std::string& path) const;
	};

	using TextureCache = entt::resource_cache<Texture>;
	using TextureHandle = entt::resource_handle<Texture>;
}