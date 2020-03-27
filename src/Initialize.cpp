#include "Initialize.h"
#include "SDL_image.h"
#include "Utils.h"
#include "Texture.h"
#include "Resource.h"

void initialize::initSDL()
{
	mAssert(
		SDL_Init(SDL_INIT_VIDEO) == 0,
		std::string("SDL could not initialize! SDL_Error: ") + SDL_GetError()
	);

	int imgFlags = IMG_INIT_PNG;
	mAssert(
		IMG_Init(imgFlags) & imgFlags,
		std::string("SDL_Image could not initialize! SDL_Error: ") + SDL_GetError()
	);
}

//// Boundary => origin bottom left, positive is up and right (world coordinates)
//void initialize::initPhysicsPlayground(const SDL_Rect& boundary, entt::registry& registry)
//{
//	b2World& world = locator::assertedRef<locator::world::service_type>();
//
//	const int xCenter = boundary.x + boundary.w / 2;
//	const int yCenter = boundary.y + boundary.h / 2;
//
//	// Horizontal ground dimensions => boundary.w / 2, 1.0f
//	// Vertical ground dimensions => 1.0f, boundary.h / 2
//
//	/*b2Body* leftGroundBody = makeGroundBody(0, yCenter, 1, boundary.h / 2);
//	loadIntoRegistry(registry, leftGroundBody);
//
//	b2Body* topGroundBody = makeGroundBody(xCenter, boundary.h, boundary.w / 2, 1);
//	loadIntoRegistry(registry, topGroundBody);
//
//	b2Body* rightGroundBody = makeGroundBody(boundary.w, yCenter, 1, boundary.h / 2);
//	loadIntoRegistry(registry, rightGroundBody);*/
//
//	// TODO: Refactor the shit out of all of these static and dynamic bodies
//	b2Body* bottomGroundBody = makeGroundBody(xCenter, boundary.h - 50, boundary.w / 2, 5);
//	component::RenderableRect rect;
//	rect.setPosition(boundary.x, boundary.h - 50);
//	rect.setWidthHeight(boundary.w, 10);
//	rect.R = 0x55;
//	rect.fillRect = false;
//	loadIntoRegistry(registry, bottomGroundBody, rect);
//}