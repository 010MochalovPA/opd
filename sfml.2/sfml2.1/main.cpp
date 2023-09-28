#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>

constexpr float BALL_SIZE = 40;
constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Moving ball");
    sf::Clock clock;

    const float positionY = 350.f;

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    sf::Vector2f speed = {100.f, 50.f};

    float offsetY = 0.f;

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

        constexpr float amplitudeY = 80.f;
        constexpr float periodY = 2;

        const float dt = clock.restart().asSeconds();
        const float wavePhase = offsetY * float(2 * M_PI);

        sf::Vector2f position = ball.getPosition();
        const float x = speed.x * dt;
        const float y = amplitudeY * std::sin(wavePhase / periodY);

        offsetY += dt;

        if ((position.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speed.x > 0))
        {
            speed.x = -speed.x;
        }
        if ((position.x < 0) && (speed.x < 0))
        {
            speed.x = -speed.x;
        }

        ball.setPosition({position.x += x, positionY + y});

        window.clear();
        window.draw(ball);
        window.display();
    }
}