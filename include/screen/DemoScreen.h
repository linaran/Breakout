#pragma once
#include <functional>
#include "SDL.h"
#include "Texture.h"
#include "DynamicBodyFactory.h"
#include "StaticBodyFactory.h"
#include "entt.hpp"
#include "Screen.h"
#include "TextureRepository.h"
#include "SpaceConverter.h"

namespace screen
{
	class DemoScreen :public Screen
	{
	public:
		DemoScreen(
			repository::TextureRepository& textureRepository,
			factory::DynamicBodyFactory* dynamicBodyFactory,
			factory::StaticBodyFactory* staticBodyFactory,
			converter::SpaceConverter& spaceConverter,
			entt::registry& registry
		);

		void start() override;

		void end() override;

		// TODO: Need to figure out what's this supposed to do
		// TODO: Need figure out how to handle screen systems
		// void update();

	private:
		repository::TextureRepository& textureRepository;
		factory::DynamicBodyFactory* dynamicBodyFactory;
		factory::StaticBodyFactory* staticBodyFactory;
		converter::SpaceConverter& spaceConverter;
		entt::registry& registry;

		entt::entity ballEntity;

		entt::entity createBall(
			const float x,
			const float y,
			std::string texturePath
		);

		void setupGround(
			const float x, 
			const float y, 
			const float halfWidth, 
			const float halfHeight
		);
	};
}