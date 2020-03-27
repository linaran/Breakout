#pragma once
#include <chrono>
#include <string>
#include "MainContrainer.h"

namespace mainLoop
{
	using dseconds = std::chrono::duration<double>;
	const dseconds physicsTimeStep{ 1 / 60.0f };
	static const int velocityIterations = 6;
	static const int positionIterations = 2;

	extern bool quitLoop;

	void loop(injection::MainContainer& mainContainer);
}
