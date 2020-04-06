#include "SpaceConverter.h"
#include "WindowEvent.h"

converter::SpaceConverter::SpaceConverter(
	const size_t screenWidth,
	const size_t screenHeight,
	entt::dispatcher& dispatcher
)
	: screenWidth(static_cast<int>(screenWidth))
	, screenHeight(static_cast<int>(screenHeight))
{
	auto windowSizeSink = dispatcher.sink<windowEvent::NewWindowSizeEvent>();
	windowSizeSink.connect<&converter::SpaceConverter::onNewWindowSize>(this);
}

component::Position2D converter::SpaceConverter::screenToWorld(const float x, const float y) const
{
	const float worldX = x * pxToMeter;
	const float worldY = -pxToMeter * y + screenHeight * pxToMeter;
	return component::Position2D{ worldX, worldY };
}

component::Position2D converter::SpaceConverter::worldToScreen(const float x, const float y) const
{
	const float screenX = x * meterToPx;
	const float screenY = -y * meterToPx + screenHeight;
	return component::Position2D{ screenX, screenY };
}

void converter::SpaceConverter::onNewWindowSize(const windowEvent::NewWindowSizeEvent& event)
{
	screenWidth = static_cast<int>(event.width);
	screenHeight = static_cast<int>(event.height);
}
