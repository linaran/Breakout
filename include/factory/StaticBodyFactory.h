#pragma once
#include "Box2D/Box2D.h"

namespace factory {
	class StaticBodyFactory
	{
	public:
		StaticBodyFactory(b2World* world);

		// Creates body from provided defs and shape
		b2Body* create(
			b2BodyDef& bodyDef,
			b2Shape& bodyShape
		);

		// Creates body from default bodyDef and shape
		b2Body* create(
			const float x,
			const float y,
			const float halfWidth,
			const float halfHeight
		);

		b2BodyDef defaultBodyDef(
			const float x,
			const float y
		);

		b2PolygonShape defaultBodyShape(
			const float halfWidth,
			const float halfHeight
		);

	private:
		b2World* world;
	};
}