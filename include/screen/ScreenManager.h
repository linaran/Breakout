#pragma once
#include <unordered_map>
#include <utility>
#include "Screen.h"

namespace screen {
	class ScreenManager
	{
	public:
		~ScreenManager();

		// TODO: Figure out how to enforce T : Screen
		template<class T, class... P>
		void showScreen(P&&... parameters)
		{
			screen::Screen* screen = new T(std::forward<P>(parameters)...);
			screen->screenId = nextId;

			activeScreens.emplace(nextId, screen);
			nextId++;

			screen->start();
		}

		void hideScreen(const size_t screenId);

	private:
		size_t nextId = 1;
		std::unordered_map<size_t, screen::Screen*> activeScreens;
	};
}