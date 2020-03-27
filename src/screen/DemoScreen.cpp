#include "DemoScreen.h"
#include "Resource.h"
#include "Components.h"

screen::DemoScreen::DemoScreen(
	repository::TextureRepository& textureRepository,
	factory::DynamicBodyFactory* dynamicBodyFactory, 
	converter::SpaceConverter& spaceConverter,
	entt::registry& registry
)
	: textureRepository(textureRepository)
	, dynamicBodyFactory(dynamicBodyFactory)
	, spaceConverter(spaceConverter)
	, registry(registry)
	, ballEntity(entt::null)
{}

void screen::DemoScreen::start()
{
	auto worldPosition = spaceConverter.screenToWorld(100.f, 100.f);
	ballEntity = createBall(worldPosition.x, worldPosition.y, "Textures/ball.png");
}

void screen::DemoScreen::end()
{
	registry.destroy(ballEntity);
}

entt::entity screen::DemoScreen::createBall(const float x, const float y, std::string texturePath)
{
	auto textureHandle = textureRepository.load(resource::texture::ball, texturePath);

	b2BodyDef bodyDef;
	bodyDef.position.Set(x, y);

	b2CircleShape bodyShape;
	bodyShape.m_radius = textureHandle->width / 2.f;

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
