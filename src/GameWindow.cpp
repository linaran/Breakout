#include "GameWindow.h"
#include <cstdio>
#include "Utils.h"

GameWindow::GameWindow(const std::string& windowName, const size_t windowWidth, const size_t windowHeight) :
	windowName(windowName),
	windowWidth(windowWidth),
	windowHeight(windowHeight)
{
	_window = SDL_CreateWindow(
		windowName.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		windowWidth,
		windowHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);
	mAssert(_window != nullptr, std::string("Window could not be created! SDL_Error: ") + SDL_GetError());

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	mAssert(_renderer != nullptr, std::string("Renderer could not be created! SDL_Error: ") + SDL_GetError());
}

GameWindow::~GameWindow()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

SDL_Window* const GameWindow::window() const
{
	return _window;
}

SDL_Renderer* const GameWindow::renderer() const
{
	return _renderer;
}
