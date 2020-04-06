#include "EventLoop.h"
#include "WindowEvent.h"

bool eventLoop::pollEvents(entt::dispatcher& dispatcher)
{
	while (SDL_PollEvent(&event) != 0)
	{
		// Handle quit signal.
		if (event.type == SDL_QUIT)
		{
			dispatcher.trigger<windowEvent::QuitEvent>();
			return true;
		}

		// Handle other events.
		if (event.type == SDL_WINDOWEVENT) onWindowEvent(dispatcher);
	}

	return false;
}

void eventLoop::onWindowEvent(entt::dispatcher& dispatcher)
{
	switch (event.window.event)
	{
	case SDL_WINDOWEVENT_SIZE_CHANGED:
	{
		const size_t width = static_cast<size_t>(event.window.data1);
		const size_t height = static_cast<size_t>(event.window.data2);
		dispatcher.trigger<windowEvent::NewWindowSizeEvent>(width, height);
	}
	break;

	case SDL_WINDOWEVENT_FOCUS_GAINED:
		dispatcher.trigger<windowEvent::FocusGainEvent>();
		break;

	case SDL_WINDOWEVENT_FOCUS_LOST:
		dispatcher.trigger<windowEvent::FocusLossEvent>();
		break;
	}
}
