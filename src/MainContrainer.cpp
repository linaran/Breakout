#include "MainContrainer.h"

injection::MainContainer::MainContainer(const std::string& windowName) 
	: _gameWindow(GameWindow(windowName))
	, world(new b2World(b2Vec2(0.0f, -10.0f)))
	, _spaceConverter(_gameWindow.windowWidth, _gameWindow.windowWidth)
	, staticBodyFactory(new factory::StaticBodyFactory(world))
	, dynamicBodyFactory(new factory::DynamicBodyFactory(world))
	, _textureRepository(repository::TextureRepository(_textureCache, _gameWindow.renderer()))
{}

injection::MainContainer::~MainContainer()
{
	delete dynamicBodyFactory;
	delete staticBodyFactory;
	delete world;
}

SDL_Window* const injection::MainContainer::window() const
{
	return _gameWindow.window();
}

SDL_Renderer* const injection::MainContainer::renderer() const
{
	return _gameWindow.renderer();
}

converter::SpaceConverter& injection::MainContainer::spaceConverter()
{
	return _spaceConverter;
}

entt::registry& injection::MainContainer::registry()
{
	return _registry;
}

resource::TextureCache& injection::MainContainer::textureCache()
{
	return _textureCache;
}

repository::TextureRepository& injection::MainContainer::textureRepository()
{
	return _textureRepository;
}

screen::ScreenManager& injection::MainContainer::screenManager()
{
	return _screenManager;
}

GameWindow& injection::MainContainer::gameWindow()
{
	return _gameWindow;
}
