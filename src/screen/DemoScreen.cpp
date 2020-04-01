#include "DemoScreen.h"
#include "Resource.h"
#include "Components.h"

screen::DemoScreen::DemoScreen(
	repository::TextureRepository& textureRepository,
	factory::DynamicBodyFactory* dynamicBodyFactory,
	factory::StaticBodyFactory* staticBodyFactory,
	converter::SpaceConverter& spaceConverter,
	entt::registry& registry
)
	: textureRepository(textureRepository)
	, dynamicBodyFactory(dynamicBodyFactory)
	, staticBodyFactory(staticBodyFactory)
	, spaceConverter(spaceConverter)
	, registry(registry)
	, ballEntity(entt::null)
{}

void screen::DemoScreen::start()
{
	ballEntity = createBall(100.f, 100.f, "ball.png");
	setupGround(210.f, 300.f, 100.f, 2.f);
}

void screen::DemoScreen::end()
{
	registry.destroy(ballEntity);
}

entt::entity screen::DemoScreen::createBall(const float x, const float y, std::string texturePath)
{
	auto worldBallPosition = spaceConverter.screenToWorld(x, y);

	auto textureHandle = textureRepository.load(resource::texture::ball, texturePath);
	const float ballDiameter = textureHandle->width * converter::pxToMeter;

	b2BodyDef bodyDef;
	bodyDef.position.Set(worldBallPosition.x, worldBallPosition.y);

	b2CircleShape bodyShape;
	bodyShape.m_radius = ballDiameter / 2.f;

	b2FixtureDef bodyFixture;
	bodyFixture.density = 1.0f;
	bodyFixture.shape = &bodyShape;
	bodyFixture.friction = 0.3f;

	auto* body = dynamicBodyFactory->create(
		bodyDef,
		bodyShape,
		bodyFixture
	);

	auto ballEntity = registry.create();
	registry.assign<component::Position2D>(ballEntity, x, y);
	registry.assign<component::Body>(ballEntity, body);
	registry.assign<component::Texture>(ballEntity, textureHandle);

	return ballEntity;
}

void screen::DemoScreen::setupGround(
	const float x,
	const float y,
	const float halfWidth,
	const float halfHeight
)
{
	auto worldGroundPosition = spaceConverter.screenToWorld(x, y);
	const float groundHalfWidth = halfWidth * converter::pxToMeter;
	const float groundHalfHeight = halfHeight * converter::pxToMeter;

	b2Body* ground = staticBodyFactory->create(
		worldGroundPosition.x,
		worldGroundPosition.y,
		groundHalfWidth,
		groundHalfHeight
	);

	auto groundEntity = registry.create();
	auto& renderableRect = registry.assign<component::RenderableRect>(groundEntity);
	renderableRect.setPosition(x - halfWidth, y - halfHeight);
	renderableRect.setWidthHeight(halfWidth * 2, halfHeight * 2);
}
