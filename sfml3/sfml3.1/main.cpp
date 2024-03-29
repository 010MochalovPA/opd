#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0X80, 0x00));
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

void update(sf::Clock &clock, const sf::Vector2f &mousePosition, sf::ConvexShape &pointer)
{
    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    float angle = toDegrees(atan2(delta.y, delta.x));
    const float currentAngle = pointer.getRotation();
    if (angle == currentAngle)
    {
        return;
    }

    if (angle < 0)
    {
        angle += 360;
    }

    const float dt = clock.restart().asSeconds();
    const float rotationLimit = 15.f;
    const float rotationSpeed = rotationLimit * dt;
    float rotateAngle = angle - currentAngle;

    const float direction = (rotateAngle > 0 && rotateAngle < 180 || rotateAngle < -180) ? 1 : -1;

    pointer.rotate(rotationSpeed * direction);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Pointer follows mouse", sf::Style::Default, settings);
    sf::Clock clock;
    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;

    init(pointer);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(clock, mousePosition, pointer);
        redrawFrame(window, pointer);
    }
}
