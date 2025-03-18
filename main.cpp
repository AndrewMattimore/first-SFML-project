#include "floorGen.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Terraria Clone", sf::Style::Default);

    floorGen floor;

    sf::Texture texture = floor.loadTexture("C:\\Users\\sgtma\\source\\repos\\first SFML project\\Debug\\tileset.png");
    sf::Sprite sprite(texture);

    std::vector<sf::Sprite> floors = floor.generateFloor(texture);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        for (const auto& sprite : floors)
        {
            window.draw(sprite);
        }

        window.display();
    }

    return 0;
}