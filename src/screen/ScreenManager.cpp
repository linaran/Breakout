#include "ScreenManager.h"

screen::ScreenManager::~ScreenManager()
{
	activeScreens.clear();
}

void screen::ScreenManager::hideScreen(const size_t screenId)
{
	if (activeScreens.find(screenId) == activeScreens.end()) return;

	Screen* screen = activeScreens[screenId];
	screen->end();
	activeScreens.erase(screenId);
}
