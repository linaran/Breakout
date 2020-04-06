#pragma once
#include "SDL_events.h"
#include "entt.hpp"

namespace eventLoop
{
	static SDL_Event event;

	bool pollEvents(entt::dispatcher& dispatcher);

	void onWindowEvent(entt::dispatcher& dispatcher);
}
