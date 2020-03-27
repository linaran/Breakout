#pragma once
#include "Box2D/Box2D.h"

namespace factory {
	class DynamicBodyFactory
	{
	public:
		DynamicBodyFactory(b2World* world);

		b2Body* create(
			b2BodyDef& bodyDef,
			b2Shape& bodyShape,
			b2FixtureDef& fixtureDef
		);

	private:
		b2World* world;
	};
}