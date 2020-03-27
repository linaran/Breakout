#pragma once
#include "SDL.h"
#include "Components.h"

namespace converter
{
	const float pxToMeter = 0.02f;
	const float meterToPx = 50.0f;

	// TODO: Support density pixels
	// TODO: Write a conversion matrix just to feel smart
	class SpaceConverter
	{
	public:
		SpaceConverter(const int screenWidth, const int screenHeight);

		component::Position2D screenToWorld(const float x, const float y) const;

		component::Position2D worldToScreen(const float x, const float y) const;

	private:
		const int screenWidth;
		const int screenHeight;
	};
}
