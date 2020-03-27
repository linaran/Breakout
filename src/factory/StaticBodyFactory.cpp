#include "StaticBodyFactory.h"

factory::StaticBodyFactory::StaticBodyFactory(b2World* world)
	: world(world)
{}

b2Body* factory::StaticBodyFactory::create(
	b2BodyDef& bodyDef,
	b2Shape& bodyShape
)
{
	b2Body* body = world->CreateBody(&bodyDef);
	body->CreateFixture(&bodyShape, 0.0f);

	return body;
}

b2Body* factory::StaticBodyFactory::create(const float x, const float y, const float halfWidth, const float halfHeight)
{
	auto bodyDef = defaultBodyDef(x, y);
	auto shape = defaultBodyShape(halfWidth, halfHeight);

	return create(
		bodyDef,
		shape
	);
}

b2BodyDef factory::StaticBodyFactory::defaultBodyDef(const float x, const float y)
{
	b2BodyDef bodyDef;
	bodyDef.position.Set(x, y);
	return bodyDef;
}

b2PolygonShape factory::StaticBodyFactory::defaultBodyShape(const float halfWidth, const float halfHeight)
{
	b2PolygonShape shape;
	shape.SetAsBox(halfWidth, halfHeight);
	return shape;
}
