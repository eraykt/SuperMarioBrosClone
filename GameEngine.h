#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "vec2.hpp"

class GameEngine
{
private:
	sf::RenderWindow m_window;

	void init();


public:
	GameEngine();
	void run();
};
