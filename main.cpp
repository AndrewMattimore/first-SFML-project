#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Terraria Clone", sf::Style::Default);

    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\sgtma\\source\\repos\\first SFML project\\Debug\\tileset.png"))
    {
        std::cerr << "Failed to load image" << std::endl;
        return -1;
    }

    std::cout << "Image Loaded successfully" << std::endl;

    const int tileSize = 32;
    const int windowWidth = 800;
    const int numTiles = windowWidth / tileSize;
    const int bottomY = 600 - tileSize;


    std::vector<sf::Sprite> textures;

    for (int i = 0; i < numTiles; i++)
    {
        sf::Sprite sprite(texture);
        sprite.setTextureRect(sf::IntRect({ 7, 3 }, { tileSize, tileSize }));
        sprite.setPosition({ static_cast<float>(i * tileSize), static_cast<float>(bottomY) });
        textures.push_back(sprite);
    }


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();


        for (const auto& sprite : textures)
        {
            window.draw(sprite);
        }

        window.display();
    }

    return 0;
}



