#include "TextureRepository.h"

repository::TextureRepository::TextureRepository(resource::TextureCache& textureCache, SDL_Renderer* renderer)
	: texturesRoot(ASSETS_ROOT)
	, textureCache(textureCache)
	, renderer(renderer)
{
	texturesRoot += "Textures/";
}

resource::TextureHandle repository::TextureRepository::load(entt::hashed_string textureId, std::string path)
{
	return textureCache.load<resource::TextureLoader>(textureId, renderer, texturesRoot + path);
}
