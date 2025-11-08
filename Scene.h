#pragma once

class GameEngine;
#include "EntityManager.h"

class Scene 
{
protected:
	GameEngine* m_game;
	EntityManager m_entities;

public:
	Scene();
	explicit Scene(GameEngine * game);

	virtual ~Scene();

	virtual void update() = 0;

};

