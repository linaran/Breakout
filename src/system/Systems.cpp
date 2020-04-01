#include "Systems.h"
#include "Components.h"
#include "Texture.h"

void renderingSystem(entt::registry& registry, SDL_Renderer* const renderer)
{
	renderTextures(registry, renderer);
	renderRects(registry, renderer);
}

void renderTextures(entt::registry& registry, SDL_Renderer* const renderer)
{
	using namespace component;

	auto view = registry.view<Position2D, Texture>();
	for (auto entity : view)
	{
		Position2D& position = view.get<Position2D>(entity);
		auto textureHandle = view.get<Texture>(entity).handle;
		const SDL_Rect destRect{
			static_cast<int>(position.x),
			static_cast<int>(position.y),
			textureHandle->width,
			textureHandle->height
		};

		// printf("Screen ball position => %f %f\n", position.x, position.y);

		// TODO: It's possible destRect is leaking here.
		// TODO: Possible fix is to refactor Position2D to store destRect in the entity.
		SDL_RenderCopy(renderer, textureHandle->sdlTexture, nullptr, &destRect);
	}
}

void renderRects(entt::registry& registry, SDL_Renderer* const renderer)
{
	using namespace component;

	RenderableRect oldColors;
	SDL_GetRenderDrawColor(renderer, &oldColors.R, &oldColors.G, &oldColors.B, &oldColors.A);

	auto view = registry.view<RenderableRect>();
	for (auto entity : view)
	{
		auto& rect = view.get(entity);

		SDL_SetRenderDrawColor(renderer, rect.R, rect.G, rect.B, rect.A);
		if (rect.fillRect)
		{
			SDL_RenderFillRect(renderer, &rect);
		} 
		else
		{
			SDL_RenderDrawRect(renderer, &rect);
		}
	}

	SDL_SetRenderDrawColor(renderer, oldColors.R, oldColors.G, oldColors.B, oldColors.A);
}

void applyPhysicsSystem(entt::registry& registry, converter::SpaceConverter& converter)
{
	using namespace component;

	auto view = registry.view<Position2D, Texture, Body>();
	for (auto entity : view)
	{
		// TODO: Three position types. Think about that...
		b2Vec2 worldPosition = view.get<Body>(entity).body->GetPosition();

		auto textureHandle = view.get<Texture>(entity).handle;
		const int textureHalfWidth = textureHandle->width / 2;
		const int textureHalfHeight = textureHandle->height / 2;

		// Position at the center of the body
		auto newScreenPosition = converter.worldToScreen(worldPosition.x, worldPosition.y);

		// Apply the corrected position so the image is rendered properly
		auto &oldScreenPosition = view.get<Position2D>(entity);
		oldScreenPosition.x = newScreenPosition.x - textureHalfWidth;
		oldScreenPosition.y = newScreenPosition.y - textureHalfHeight;
	}
}

void dumpPhysicsBody(entt::registry& registry)
{
	using namespace component;

	int i = 0;
	auto view = registry.view<Body>();
	for (auto entity : view)
	{
		auto *body = view.get(entity).body;
		auto &position = body->GetPosition();
		printf("%d: Body => %4.2f %4.2f\n", i++, position.x, position.y);
	}
	printf("\n");
}
