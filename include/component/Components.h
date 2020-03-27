#pragma once
#include "entt.hpp"
#include "Texture.h"
#include "Box2D/Box2D.h"

namespace component
{
	struct Position2D
	{
		float x = 0.0f, y = 0.0f;
	};

	struct Texture
	{
		resource::TextureHandle handle;
	};

	struct Body
	{
		b2Body* body = nullptr;
	};

	struct RenderableRect : SDL_Rect
	{
		Uint8 R = 0xFF, G = 0xFF, B = 0xFF, A = 0xFF;
		bool fillRect = false;

		inline void setRGBA(const Uint8 R, const Uint8 G, const Uint8 B, Uint8 A)
		{
			this->R = R;
			this->G = G;
			this->B = B;
			this->A = A;
		}

		inline void setPosition(const int x, const int y)
		{
			this->x = x;
			this->y = y;
		}

		inline void setWidthHeight(const int width, const int height)
		{
			w = width;
			h = height;
		}
	};
}