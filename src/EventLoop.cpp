#include "EventLoop.h"
#include <cstdio>

bool eventLoop::pollEvents()
{
	while (SDL_PollEvent(&event) != 0)
	{
		// Handle quit signal.
		if (event.type == SDL_QUIT) {
			return true;
		}


		// Handle other events.
	}

	return false;
}
