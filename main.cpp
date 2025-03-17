#include "floorGen.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Terraria Clone", sf::Style::Default);

    const int tileSize = 32;
    const int windowWidth = 800;
    const int numTiles = windowWidth / tileSize;
    const int bottomY = 600 - tileSize;

    floorGen floor;

    sf::Texture texture = floor.loadTexture("C:\\Users\\sgtma\\source\\repos\\first SFML project\\Debug\\tileset.png");
    sf::Sprite sprite(texture);

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