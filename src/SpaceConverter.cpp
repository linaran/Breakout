#include "SpaceConverter.h"

converter::SpaceConverter::SpaceConverter(const int screenWidth, const int screenHeight) :
	screenWidth(screenWidth),
	screenHeight(screenHeight)
{}

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
