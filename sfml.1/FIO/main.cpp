#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({920, 360}), "fio");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({60, 300});
    shape1.setPosition({30, 30});
    shape1.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({60, 150});
    shape2.setRotation({-45});
    shape2.setPosition({47, 71});
    shape2.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({60, 150});
    shape3.setRotation({225});
    shape3.setPosition({154, 180});
    shape3.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({60, 300});
    shape4.setPosition({220, 30});
    shape4.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({60, 300});
    shape5.setPosition({320, 30});
    shape5.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({60, 300});
    shape6.setPosition({500, 30});
    shape6.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({240, 60});
    shape7.setPosition({320, 30});
    shape7.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({60, 300});
    shape8.setOrigin(30, 30);
    shape8.setRotation({20});
    shape8.setPosition({720, 70});
    shape8.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({60, 300});
    shape9.setOrigin(30, 30);
    shape9.setRotation({-20});
    shape9.setPosition({740, 70});
    shape9.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape9);

    sf::RectangleShape shape10;
    shape10.setSize({60, 60});
    shape10.setPosition({700, 30});
    shape10.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape10);

    sf::RectangleShape shape11;
    shape11.setSize({160, 60});
    shape11.setPosition({650, 180});
    shape11.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape11);

    window.display();

    sf::sleep(sf::seconds(10));
}