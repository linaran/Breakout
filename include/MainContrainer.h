#pragma once
#include <string>
#include "GameWindow.h"
#include "SDL.h"
#include "Box2D/Box2D.h"
#include "SpaceConverter.h"
#include "entt.hpp"
#include "StaticBodyFactory.h"
#include "DynamicBodyFactory.h"
#include "Texture.h"
#include "ScreenManager.h"
#include "TextureRepository.h"

namespace injection
{
	struct MainContainer
	{
		MainContainer(const std::string& windowName);

		~MainContainer();

		GameWindow& gameWindow();

		SDL_Window* const window() const;

		SDL_Renderer* const renderer() const;

		converter::SpaceConverter& spaceConverter();

		entt::registry& registry();

		resource::TextureCache& textureCache();

		repository::TextureRepository& textureRepository();

		screen::ScreenManager& screenManager();

		b2World* const world;

	private:
		// Those bound to the main lifecycle must be declared in private
		// and returned through getters.

		GameWindow _gameWindow;
		converter::SpaceConverter _spaceConverter;
		entt::registry _registry;
		resource::TextureCache _textureCache;
		screen::ScreenManager _screenManager;
		repository::TextureRepository _textureRepository;

	public:
		factory::StaticBodyFactory* const staticBodyFactory;
		factory::DynamicBodyFactory* const dynamicBodyFactory;
	};
}
