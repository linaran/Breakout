#pragma once
#include "SDL.h"
#include "Components.h"
#include "WindowEvent.h"
#include "entt.hpp"

namespace converter
{
	const float pxToMeter = 0.02f;
	const float meterToPx = 50.0f;

	// TODO: Support density pixels
	// TODO: Write a conversion matrix just to feel smart
	class SpaceConverter
	{
	public:
		SpaceConverter(const size_t screenWidth, const size_t screenHeight, entt::dispatcher &dispatcher);

		component::Position2D screenToWorld(const float x, const float y) const;

		component::Position2D worldToScreen(const float x, const float y) const;

		void onNewWindowSize(const windowEvent::NewWindowSizeEvent& event);

	private:
		int screenWidth;
		int screenHeight;
	};
}
