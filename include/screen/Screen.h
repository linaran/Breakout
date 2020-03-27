#pragma once

namespace screen
{
	class ScreenManager;

	struct Screen
	{
		virtual ~Screen() {}

		virtual void start() = 0;

		virtual void end() = 0;

	protected:
		size_t screenId;

		friend class ScreenManager;
	};
}