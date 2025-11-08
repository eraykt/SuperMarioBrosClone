#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "vec2.hpp"
#include "Scene.h"
#include "map"
#include <memory>
#include "Assets.h"

class GameEngine
{
private:
	sf::RenderWindow m_window;

	Assets m_assets;

	std::map<std::string, std::shared_ptr<Scene>> m_sceneMap;
	std::string m_curretScene;

	void init(const std::string& path);

public:
	GameEngine(const std::string& path);
	void run();

	void changeScene(const std::string& sceneName, std::shared_ptr<Scene> scene);
};
