#pragma once
#include "SDL_events.h"

namespace eventLoop 
{
	static SDL_Event event;

	bool pollEvents();
}
