#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr int pointCount = 200;

    sf::Clock clock;
    const sf::Vector2f position = {10, 350};

    const float radius = 80.f;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), "Ellipse",
        sf::Style::Default, settings);

    sf::ConvexShape shape;
    shape.setPosition({400, 320});
    shape.setFillColor(sf::Color(0xFF, 0x09, 0x80));

    shape.setPointCount(pointCount);

    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        float radius = 200 * sin(6 * angle);

        sf::Vector2f point = {
            radius * std::sin(angle),
            radius * std::cos(angle)};
        shape.setPoint(pointNo, point);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        constexpr float speedX = 100.f;

        const float time = clock.getElapsedTime().asSeconds();
        const float wavePhase = time * float(2 * M_PI);
        const float x = radius * std::sin(wavePhase / 2);
        const float y = radius * std::con(wavePhase / 2);

        const sf::Vector2f offset = {x, y};

        shape.setPosition(position + offset);

        window.clear();
        window.draw(shape);
        window.display();
    }
}