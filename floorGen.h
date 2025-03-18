#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

class floorGen
{
private:
	const int tileSize = 32;
	const int windowWidth = 800;
	const int numTiles = windowWidth / tileSize;
	const int bottomY = 600 - tileSize;

public:

	sf::Texture loadTexture(std::string);
	std::vector<sf::Sprite> generateFloor(sf::Texture& texture);

};

