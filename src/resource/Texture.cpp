#include "Texture.h"
#include "SDL_image.h"
#include "SDL_log.h"
#include "Surface.h"

resource::Texture::Texture(SDL_Renderer* renderer, const std::string& path) :
	sdlTexture(SDL_CreateTextureFromSurface(renderer, Surface(path).surface)),
	width(queryTextureWidth()),
	height(queryTextureHeight())
{
	if (sdlTexture == nullptr) 
	{
		SDL_LogWarn(SDL_LOG_CATEGORY_ASSERT, "CreateTextureFromSurface: %s", SDL_GetError());
	}
}

resource::Texture::~Texture()
{
	SDL_DestroyTexture(sdlTexture);
}

const int resource::Texture::queryTextureWidth()
{
	int retValue = 0;
	SDL_QueryTexture(sdlTexture, nullptr, nullptr, &retValue, nullptr);
	return retValue;
}

const int resource::Texture::queryTextureHeight()
{
	int retValue = 0;
	SDL_QueryTexture(sdlTexture, nullptr, nullptr, nullptr, &retValue);
	return retValue;
}

std::shared_ptr<resource::Texture> resource::TextureLoader::load(
	SDL_Renderer* renderer, 
	const std::string& path) const
{
	return std::make_shared<resource::Texture>(renderer, path);
}
