#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void update(sf::Vector2f &mousePosition, sf::ConvexShape &arrow, sf::Clock &clock, float &angleDegrees)
{
    const sf::Vector2f position = arrow.getPosition();
    const sf::Vector2f delta = mousePosition - position;
    float speed = 20.f;
    const float deltaTime = clock.restart().asSeconds();
    const float deltaNormal = sqrtf(delta.x * delta.x + delta.y * delta.y);

    if (deltaNormal)
    {
        const float angle = atan2(delta.y, delta.x);
        const float maxAngle = 90.0 * deltaTime;
        const sf::Vector2f direction = delta / deltaNormal;

        float deltaAngle = toDegrees(angle) - angleDegrees;

        if (deltaAngle < -180)
        {
            deltaAngle = deltaAngle + 360;
        }

        if (deltaAngle > 180)
        {
            deltaAngle = deltaAngle - 360;
        }

        if (deltaAngle > 0)
        {
            angleDegrees = angleDegrees + std::min(deltaAngle, maxAngle);
        }
        else
        {
            angleDegrees = angleDegrees + -std::min(-deltaAngle, maxAngle);
        }

        if (angleDegrees < -360)
        {
            angleDegrees = angleDegrees + 360;
        }

        if (angleDegrees > 360)
        {
            angleDegrees = angleDegrees - 360;
        }

        arrow.setRotation(angleDegrees);
        arrow.setPosition(position + direction * speed * deltaTime);
    }
}

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
    float angleDegrees = 0;
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);

        update(mousePosition, arrow, clock, angleDegrees);
        window.clear(sf::Color(255, 255, 255));
        window.draw(arrow);
        window.display();
    }
    return 0;
}
