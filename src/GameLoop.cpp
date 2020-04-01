#include <cstdio>
#include "GameLoop.h"
#include "EventLoop.h"
#include "Systems.h"
#include "ScreenManager.h"
#include "DemoScreen.h"

bool mainLoop::quitLoop = false;

void mainLoop::loop(injection::MainContainer& mainContainer)
{
	using namespace std;
	using namespace chrono;
	using namespace placeholders;

	// TODO: Decide, local vars or access from mainContainer
	b2World* world = mainContainer.world;
	entt::registry& registry = mainContainer.registry();
	GameWindow& gameWindow = mainContainer.gameWindow();
	screen::ScreenManager& screenManager = mainContainer.screenManager();

	// TODO: Hardcoded first and only screen
	screenManager.showScreen<screen::DemoScreen>(
		mainContainer.textureRepository(),
		mainContainer.dynamicBodyFactory,
		mainContainer.staticBodyFactory,
		mainContainer.spaceConverter(),
		registry
		);

	dseconds time{ 0 };

	auto frameStart{ high_resolution_clock::now() };
	dseconds lag{ 0 };

	while (!quitLoop)
	{
		// Calculate duration of the last frame.
		auto frameEnd = high_resolution_clock::now();
		dseconds frameDuration = frameEnd - frameStart;

		// Begin next frame.
		frameStart = high_resolution_clock::now();

		// Event loop.
		quitLoop = eventLoop::pollEvents();

		// Possible screen management if needed
		// TODO:

		lag += frameDuration;
		while (lag >= physicsTimeStep)
		{
			// Update physics.
			world->Step(physicsTimeStep.count(), velocityIterations, positionIterations);
			applyPhysicsSystem(registry, mainContainer.spaceConverter());
			//dumpPhysicsBody(registry);

			lag -= physicsTimeStep;
			time += physicsTimeStep;
		}

		// Render frame.
		SDL_RenderClear(gameWindow.renderer());
		renderingSystem(registry, gameWindow.renderer());
		SDL_RenderPresent(gameWindow.renderer());
	}
}