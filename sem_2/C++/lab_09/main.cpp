#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>

int getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

float calculateDistance(float x1, float y1, float x2, float y2) {
    return std::sqrt(std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2));
}

int main()
{
    const unsigned int windowWidth = 900u,
                       widowHeigth = 600u;
    

    auto window = sf::RenderWindow(sf::VideoMode({windowWidth, widowHeigth}), "SFML", sf::Style::Titlebar | sf::Style::Close);
 
    const unsigned int tankWidth = 80u,
                       tankHeigth = 80u,
                       muzzleWidth = 20u,
                       muzzleHeigth = 50u;

    const unsigned int MD = (tankWidth - muzzleWidth) / 2;
    sf::Font font;
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "font error\n";
        return -1;
    }
    unsigned int score = 0;
    
    sf::Text scoreText(font, "SCORE: " + std::to_string(score));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(sf::Vector2f(10.f, 10.f));
    
    float tankPosX = 100.f, tankPosY = 100.f;
    
    sf::ConvexShape tankShape;
    tankShape.setPointCount(8);

    unsigned int pointIndex = 0;
    
    tankShape.setPoint(pointIndex++, sf::Vector2f(0, muzzleHeigth));
    tankShape.setPoint(pointIndex++, sf::Vector2f(0, muzzleHeigth + tankHeigth));
    tankShape.setPoint(pointIndex++, sf::Vector2f(tankWidth, muzzleHeigth + tankHeigth));
    tankShape.setPoint(pointIndex++, sf::Vector2f(tankWidth, muzzleHeigth));
    tankShape.setPoint(pointIndex++, sf::Vector2f(MD + muzzleWidth, muzzleHeigth));
    tankShape.setPoint(pointIndex++, sf::Vector2f(MD + muzzleWidth, 0));
    tankShape.setPoint(pointIndex++, sf::Vector2f(MD, 0));
    tankShape.setPoint(pointIndex++, sf::Vector2f(MD, muzzleHeigth));

    tankShape.setFillColor(sf::Color::Green);

    tankShape.setPosition(sf::Vector2f(0, widowHeigth - (muzzleHeigth + tankHeigth)));

    sf::RectangleShape line(sf::Vector2f(windowWidth, 3.f));
    line.setPosition(sf::Vector2f(0.f, widowHeigth - tankHeigth - muzzleHeigth -  5.f));
    line.setFillColor(sf::Color::Blue);

    std::vector<sf::CircleShape> bullets;
    std::vector<sf::CircleShape> enemies;

    sf::Clock clock;
    sf::Clock bulletTimer;
    sf::Clock enemyTimer;
    
    float tankV = 360.f;
    float bulletV = 500.f;
    float enemyV = 50.f;
    
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();

        if (enemyTimer.getElapsedTime().asSeconds() >= 1.f) {
            enemyTimer.restart();
            sf::CircleShape enemy(muzzleWidth * 0.75);
            enemy.setOrigin(sf::Vector2f(muzzleWidth * 0.75, muzzleWidth * 0.75));
            enemy.setPosition(sf::Vector2f((float)getRandomNumber(MD, (int)(windowWidth - muzzleWidth * 0.75 - MD)), 0.f));
            enemy.setFillColor(sf::Color::Yellow);
            enemies.push_back(enemy);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            if (tankShape.getPosition().x <= windowWidth - tankWidth)
                tankShape.move({tankV * dt, 0.f});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            if (tankShape.getPosition().x >= 0)
                tankShape.move({-(tankV * dt), 0.f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            if (bulletTimer.getElapsedTime().asSeconds() >= 0.5f) {
                    bulletTimer.restart();
                    sf::CircleShape bullet(muzzleWidth / 2);
                    bullet.setOrigin(sf::Vector2f(muzzleWidth / 2, muzzleWidth / 2));
                    bullet.setPosition(sf::Vector2f(tankShape.getPosition().x + muzzleWidth / 2 + MD, tankShape.getPosition().y));
                    bullet.setFillColor(sf::Color::Red);
                    bullets.push_back(bullet);
                }
        }

        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].move(sf::Vector2f(0.f, -(bulletV * dt)));
        }

        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].move(sf::Vector2f(0.f, enemyV * dt));
            if (enemies[i].getPosition().y >= (widowHeigth - tankHeigth - muzzleHeigth - muzzleWidth * 0.75)) {
                window.close();
                std::cout << "Your score: " << score << std::endl;
            }
        }

        for (auto i = bullets.begin(); i != bullets.end(); ) {
            bool bulletDestroyed = false;
            for (auto j = enemies.begin(); j != enemies.end(); ) {
                if (calculateDistance(i->getPosition().x, i->getPosition().y, 
                    j->getPosition().x, j->getPosition().y) <= muzzleWidth / 2 + muzzleWidth * 0.75) {
                    scoreText.setString("SCORE: " + std::to_string(++score));

                    i = bullets.erase(i);
                    j = enemies.erase(j);
        
                    bulletDestroyed = true;
                } else {
                    ++j;
                }
        
                if (bulletDestroyed) break;
            }
        
            if (!bulletDestroyed) {
                ++i;
            }
        }


        window.clear();
        window.draw(tankShape);
        window.draw(scoreText);
        window.draw(line);
        for (int i = 0; i < bullets.size(); i++) {
            window.draw(bullets[i]);
        }
        for (int i = 0; i < enemies.size(); i++) {
            window.draw(enemies[i]);
        }
        window.display();
    }
}