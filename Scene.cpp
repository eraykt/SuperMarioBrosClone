#include "Scene.h"

Scene::Scene() = default;

Scene::Scene(GameEngine* game)
{
	m_game = game;
}

Scene::~Scene() = default;

