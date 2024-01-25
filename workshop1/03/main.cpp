#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void redrawFrame(sf::RenderWindow &window, sf::Sprite sprite, sf::Texture texture)
{
    window.clear(sf::Color(255, 255, 255));
    window.draw(sprite);
    window.display();
}

void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "sprite", sf::Style::Default, settings);

    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile("cat.png"))
    {
        std::cout << "Error loading texture!" << std::endl;
        return 1;
    }

    sprite.setTexture(texture);
    sprite.setPosition({400, 300});

    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window, sprite, texture);
    }
}