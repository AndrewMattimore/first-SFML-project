#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Terraria Clone");

    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\sgtma\\source\\repos\\first SFML project\\Debug\\tileset.png", false, sf::IntRect({ 10, 10 }, { 32, 32 })))
    {
        std::cerr << "Failed to load image" << std::endl;
    }

    std::cout << "Image Loaded successfully" << std::endl;

    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) // New event loop format
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        window.display();
    }

    return 0;
}
