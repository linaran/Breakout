#pragma once
#include <string>
#include "SDL.h"

// CPP class wrapper around SDL_Surface
struct Surface
{
	Surface(const std::string& path);

	~Surface();

	SDL_Surface* const surface;
};

