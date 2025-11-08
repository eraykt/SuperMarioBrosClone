#include "GameEngine.h"
#include "EntityManager.h"

GameEngine::GameEngine()
{
	init();
}

void GameEngine::init()
{
	m_window.create(sf::VideoMode(1280, 720), "Super Mario Bros");
}

void GameEngine::run()
{
	while (true)
	{
		m_window.display();
	}
}
