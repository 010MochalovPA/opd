#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({640, 480}), "home");

    window.clear(sf::Color::White);
    sf::RectangleShape shape1;
    shape1.setOrigin(200, 100);
    shape1.setSize({400, 200});
    shape1.setPosition({320, 340});
    shape1.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape1);

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0xFF, 0, 0xFF));
    trapeze.setPosition(320, 250);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-260, 0});
    trapeze.setPoint(1, {-220, -90});
    trapeze.setPoint(2, {220, -90});
    trapeze.setPoint(3, {260, 0});

    sf::RectangleShape shape2;
    shape2.setSize({60, 100});
    shape2.setPosition({390, 100});
    shape2.setFillColor(sf::Color(0x50, 0x50, 0x50));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({100, 160});
    shape3.setPosition({160, 280});
    shape3.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape3);

    sf::CircleShape circle1(15);
    circle1.setPosition({400, 50});
    circle1.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(circle1);

    sf::CircleShape circle2(20);
    circle2.setPosition({377, 30});
    circle2.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(circle2);

    sf::CircleShape circle3(16);
    circle3.setPosition({395, 22});
    circle3.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(circle3);

    sf::CircleShape circle5(22);
    circle5.setPosition({370, 5});
    circle5.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(circle5);

    window.draw(trapeze);

    window.display();

    sf::sleep(sf::seconds(10));
}