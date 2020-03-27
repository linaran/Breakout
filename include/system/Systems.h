#pragma once
#include <SDL.h>
#include "entt.hpp"
#include "SpaceConverter.h"

void renderingSystem(entt::registry &registry, SDL_Renderer* const renderer);

static void renderTextures(entt::registry& registry, SDL_Renderer* const renderer);

static void renderRects(entt::registry& registry, SDL_Renderer* const renderer);

void applyPhysicsSystem(entt::registry& registry, converter::SpaceConverter& converter);

void dumpPhysicsBody(entt::registry& registry);