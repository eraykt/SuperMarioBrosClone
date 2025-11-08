#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

class Assets
{
private:
	std::map<std::string, sf::Texture> m_textureMap;
	std::map<std::string, sf::Font> m_fontMap;

public:
	Assets();

	void loadFromFile(const std::string& path);

	void addTexture(const std::string& name, const std::string& path);
	void addFont(const std::string& name, const std::string& path);

	const sf::Texture& getTexture(const std::string&) const;
	const sf::Font& getFont(const std::string&) const;
};

