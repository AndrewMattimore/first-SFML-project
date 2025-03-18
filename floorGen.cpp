#include "floorGen.h"

sf::Texture floorGen::loadTexture(std::string filepath)
{
	sf::Texture texture;
	if (!texture.loadFromFile(filepath))
	{
		std::cerr << "Failed to load image: " << filepath << " could not find source file." << std::endl;
	}

	std::cout << "Image loaded successfully" << std::endl;
	return texture;

}

std::vector<sf::Sprite> floorGen::generateFloor(sf::Texture& texture)
{
	std::vector<sf::Sprite> floorSprites;
	for (int i = 0; i < numTiles; i++)
	{
		sf::Sprite sprite(texture);
		sprite.setTextureRect(sf::IntRect({ 7, 3 }, { tileSize, tileSize }));
		sprite.setPosition({ static_cast<float>(i * tileSize), static_cast<float>(bottomY) });
		floorSprites.push_back(sprite);
	}

	return floorSprites;

}