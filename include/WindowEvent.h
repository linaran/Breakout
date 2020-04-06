#pragma once

namespace windowEvent
{
    struct QuitEvent {};

    struct FocusGainEvent {};

    struct FocusLossEvent {};

    struct NewWindowSizeEvent 
	{
		const size_t width;
		const size_t height;
	};
}