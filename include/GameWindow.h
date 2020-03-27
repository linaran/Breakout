#pragma once
#include <string>
#include <SDL.h>

class GameWindow
{
public:
	const std::string windowName;
	const size_t windowWidth;
	const size_t windowHeight;

	GameWindow(
		const std::string& windowName,
		const size_t windowWidth = 640,
		const size_t windowHeight = 480
	);

	~GameWindow();

	// TODO: See how to prevent outsiders from deleting these pointers.
	SDL_Window* const window() const;

	SDL_Renderer* const renderer() const;

private:
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
};

