#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Draw arrow", sf::Style::Default, settings);

    sf::ConvexShape arrow;
    sf::Vector2f mousePosition;

    sf::Clock clock;

    arrow.setPosition({300, 300});
    arrow.setPointCount(7);
    arrow.setPoint(0, {40, 0});
    arrow.setPoint(1, {0, -40});
    arrow.setPoint(2, {0, -20});
    arrow.setPoint(3, {-40, -20});
    arrow.setPoint(4, {-40, 20});
    arrow.setPoint(5, {0, 20});
    arrow.setPoint(6, {0, 40});
    arrow.setFillColor(sf::Color(255, 255, 0));
    arrow.setOutlineThickness(2.0);
    arrow.setOutlineColor(sf::Color(0, 0, 0));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear(sf::Color(255, 255, 255));
        window.draw(arrow);
        window.display();
    }
    return 0;
}
