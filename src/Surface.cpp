#include "Surface.h"
#include "SDL_image.h"

Surface::Surface(const std::string& path) :
	surface(IMG_Load(path.c_str()))
{
	if (surface == nullptr)
	{
		// TODO: Log a warning!
		// SDL_GetError()!
	}
}

Surface::~Surface()
{
	SDL_FreeSurface(surface);
}
