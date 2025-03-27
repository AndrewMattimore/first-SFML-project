#include "floorGen.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Terraria Clone", sf::Style::Default);

    floorGen floor;

    sf::Texture texture = floor.loadTexture("C:\\Users\\sgtma\\source\\repos\\first SFML project\\Debug\\tileset.png");
    sf::Sprite sprite(texture);

    std::vector<sf::Sprite> floors = floor.generateFloor(texture);
    
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color(100, 250, 50));

    circle.setPosition({ 50, 50 });

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
        window.draw(circle);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            circle.move({ -0.1f, 0.f });
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            circle.move({ 0.1f, 0.f });
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            circle.move({ 0.f, 0.1f });
        }
           
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            circle.move({ 0.f, -0.1f });
        }
        window.display();
    }

    return 0;
}