#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

const sf::Vector2f EYE_RADIUS = {50, 100};
const sf::Vector2f PUPIL_RADIUS = {15, 25};
const float POINTS_COUNT = 200;

struct Eye
{
    sf::ConvexShape eye;
    sf::ConvexShape pupil;
    sf::Vector2f position;
    float rotation = 0;
};

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout
        << "x:"
        << float(event.x)
        << ", y: "
        << float(event.y)
        << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

sf::Vector2f toEuclidean(float radius, float angle)
{
    return {float(radius * cos(angle)), float(radius * sin(angle))};
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void updatePupil(Eye &eye, const sf::Vector2f &mousePosition)
{
    //
    const float length = std::sqrt(std::pow(mousePosition.x - eye.position.x, 2) + std::pow(mousePosition.y - eye.position.y, 2));
    const float offset = length > 30 ? 30 : length;
    //
    const sf::Vector2f eyeOffset = toEuclidean(offset, eye.rotation);
    eye.pupil.setPosition(eye.position + eyeOffset);
}

void initPupil(Eye &eye, sf::Vector2f position)
{
    eye.pupil.setPosition(position);
    eye.pupil.setFillColor(sf::Color(0x0, 0x0, 0x0));

    eye.pupil.setPointCount(POINTS_COUNT);
    for (int pointIndex = 0; pointIndex < POINTS_COUNT; pointIndex++)
    {
        float angle = float(2 * M_PI * pointIndex) / float(POINTS_COUNT);
        sf::Vector2f point = {float(PUPIL_RADIUS.x * std::sin(angle)), float(PUPIL_RADIUS.y * std::cos(angle))};
        eye.pupil.setPoint(pointIndex, point);
    }
}

void initEye(Eye &eye, sf::Vector2f position)
{
    eye.eye.setFillColor(sf::Color(0xff, 0xff, 0xff));

    eye.position = position;
    eye.eye.setPosition(position);

    eye.eye.setPointCount(POINTS_COUNT);
    for (int pointIndex = 0; pointIndex < POINTS_COUNT; pointIndex++)
    {
        float angle = float(2 * M_PI * pointIndex) / float(POINTS_COUNT);
        sf::Vector2f point = {float(EYE_RADIUS.x * std::sin(angle)), float(EYE_RADIUS.y * std::cos(angle))};
        eye.eye.setPoint(pointIndex, point);
    }

    initPupil(eye, position);
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

void update(const sf::Vector2f &mousePosition, Eye &eye)
{
    const sf::Vector2f delta = mousePosition - eye.position;
    eye.rotation = atan2(delta.y, delta.x);
    updatePupil(eye, mousePosition);
}

void redrawFrame(sf::RenderWindow &window, Eye &leftEye, Eye &rightEye)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
    window.clear();
    window.draw(leftEye.eye);
    window.draw(leftEye.pupil);
    window.draw(rightEye.eye);
    window.draw(rightEye.pupil);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Eyes", sf::Style::Default, settings);

    Eye leftEye;
    Eye rightEye;

    sf::Vector2f leftEyePosition = {330, 200};
    sf::Vector2f rightEyePosition = {470, 200};

    initEye(leftEye, leftEyePosition);
    initEye(rightEye, rightEyePosition);

    sf::Vector2f mousePosition;

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, leftEye);
        update(mousePosition, rightEye);
        redrawFrame(window, leftEye, rightEye);
    }
}