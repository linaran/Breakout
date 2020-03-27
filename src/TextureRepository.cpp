#include "TextureRepository.h"

repository::TextureRepository::TextureRepository(resource::TextureCache& textureCache, SDL_Renderer* renderer)
	: textureCache(textureCache)
	, renderer(renderer)
{}

resource::TextureHandle repository::TextureRepository::load(entt::hashed_string textureId, std::string path)
{
	return textureCache.load<resource::TextureLoader>(textureId, renderer, path);
}
