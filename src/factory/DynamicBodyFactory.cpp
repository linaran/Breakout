#include "DynamicBodyFactory.h"

factory::DynamicBodyFactory::DynamicBodyFactory(b2World* world)
	: world(world)
{}

b2Body* factory::DynamicBodyFactory::create(b2BodyDef& bodyDef, b2Shape& bodyShape, b2FixtureDef& fixtureDef)
{
	bodyDef.type = b2_dynamicBody;
	b2Body* body = world->CreateBody(&bodyDef);
	fixtureDef.shape = &bodyShape;
	body->CreateFixture(&fixtureDef);

	return body;
}
