#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({640u, 480u}), "SFML");
    window.setFramerateLimit(10);

    sf::CircleShape circle(50.f);
    sf::RectangleShape square({100.f, 100.f});
    sf::RectangleShape rectangle({150.f, 100.f});

    sf::Vector2f circleOrigin(circle.getRadius(), circle.getRadius());
    sf::Vector2f squareOrigin(square.getSize().x / 2, square.getSize().y / 2);
    sf::Vector2f rectangleOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);

    circle.setOrigin(circleOrigin);
    square.setOrigin(squareOrigin);
    rectangle.setOrigin(rectangleOrigin);


    float posX = 100.f, posY = 100.f;

    circle.setPosition(sf::Vector2f(posX, posY));
    square.setPosition(sf::Vector2f(posX + 150.f, posY));
    rectangle.setPosition(sf::Vector2f(posX, posY+ 150.f));

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
        {
            circle.setFillColor(sf::Color::Red);
            square.setFillColor(sf::Color::Red);
            rectangle.setFillColor(sf::Color::Red);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G))
        {
            circle.setFillColor(sf::Color::Green);
            square.setFillColor(sf::Color::Green);
            rectangle.setFillColor(sf::Color::Green);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::B))
        {
            circle.setFillColor(sf::Color::Blue);
            square.setFillColor(sf::Color::Blue);
            rectangle.setFillColor(sf::Color::Blue);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            circle.move({0.f, -1.f});
            square.move({0.f, -1.f});
            rectangle.move({0.f, -1.f});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            circle.move({0.f, 1.f});
            square.move({0.f, 1.f});
            rectangle.move({0.f, 1.f});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            circle.move({1.f, 0.f});
            square.move({1.f, 0.f});
            rectangle.move({1.f, 0.f});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            circle.move({-1.f, 0.f});
            square.move({-1.f, 0.f});
            rectangle.move({-1.f, 0.f});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            circle.rotate(sf::degrees(10.f));
            square.rotate(sf::degrees(10.f));
            rectangle.rotate(sf::degrees(10.f));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            circle.rotate(sf::degrees(-10.f));
            square.rotate(sf::degrees(-10.f));
            rectangle.rotate(sf::degrees(-10.f));
        }

        window.clear();
        window.draw(circle);
        window.draw(square);
        window.draw(rectangle);
        window.display();
    }
}