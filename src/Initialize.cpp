#include "Initialize.h"
#include "SDL_image.h"
#include "Utils.h"
#include "Texture.h"
#include "Resource.h"

void initialize::initSDL()
{
	mAssert(
		SDL_Init(SDL_INIT_VIDEO) == 0,
		std::string("SDL could not initialize! SDL_Error: ") + SDL_GetError()
	);

	int imgFlags = IMG_INIT_PNG;
	mAssert(
		IMG_Init(imgFlags) & imgFlags,
		std::string("SDL_Image could not initialize! SDL_Error: ") + SDL_GetError()
	);
}