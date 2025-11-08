#include "GameEngine.h"
#include "EntityManager.h"
#include "Scene_Play.h"

GameEngine::GameEngine(const std::string& path)
{
	init(path);
}

void GameEngine::init(const std::string& path)
{
	m_assets.loadFromFile(path);

	m_window.create(sf::VideoMode(1280, 720), "Super Mario Bros");

	changeScene("game", std::make_shared<Scene_Play>(this));
}

void GameEngine::run()
{
	while (true)
	{
		m_window.display();
	}
}

void GameEngine::changeScene(const std::string& sceneName, std::shared_ptr<Scene> scene)
{
	m_curretScene = sceneName;
	m_sceneMap[sceneName] = scene;
}
