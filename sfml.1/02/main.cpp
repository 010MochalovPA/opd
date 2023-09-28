#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({200, 540}), "lights");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({180, 520});
    shape1.setPosition({10, 10});
    shape1.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape1);

    sf::CircleShape shape2(80);
    shape2.setPosition({20, 20});
    shape2.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(80);
    shape3.setPosition({20, 190});
    shape3.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(shape3);

    sf::CircleShape shape4(80);
    shape4.setPosition({20, 360});
    shape4.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}