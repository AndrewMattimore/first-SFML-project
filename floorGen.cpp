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