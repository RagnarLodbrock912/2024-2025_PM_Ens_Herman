#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <thread>
#include <chrono>

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
    const unsigned int windowWidth = 1800u,
                       widowHeigth = 930u;
    

    auto window = sf::RenderWindow(sf::VideoMode({windowWidth, widowHeigth}), "SFML", sf::Style::Titlebar | sf::Style::Close);
 
    const unsigned int tankWidth = 180u,
                       tankHeigth = 180u,
                       muzzleWidth = 50u,
                       muzzleHeigth = 50u;

    const unsigned int MD = (tankWidth - muzzleWidth) / 2 + 5;
    sf::Font font;
    if (!font.openFromFile("../../lib/textures/press-start-k.ttf")) {
        std::cerr << "font error\n";
        return -1;
    }
    unsigned int score = 0;
    
    sf::Text scoreText(font, "SCORE: " + std::to_string(score));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(sf::Vector2f(10.f, 10.f));
    
    sf::Text finishText(font, "        YOUR SCORE: " + std::to_string(score) + "\nTO RESTART PRESS X");
    finishText.setCharacterSize(56);
    finishText.setFillColor(sf::Color::Red);
    
    finishText.setPosition(sf::Vector2f(
        window.getSize().x * 0.25,
        window.getSize().y * 0.3
    ));

    float tankPosX = 100.f, tankPosY = 100.f;    

    sf::Texture tankTexture;
    if (!tankTexture.loadFromFile("../../lib/textures/Picsart_25-04-12_04-11-00-808.png")) {
        return -1;
    }

    sf::Sprite tankSprite(tankTexture);
    tankSprite.setTexture(tankTexture);

    tankSprite.setScale(sf::Vector2f(
        tankWidth / static_cast<float>(tankTexture.getSize().x),
        tankHeigth / static_cast<float>(tankTexture.getSize().y)
    ));

    tankSprite.setPosition(sf::Vector2f(0, widowHeigth - (muzzleHeigth + tankHeigth)));

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../../lib/textures/Picsart_25-04-12_05-01-29-179.png")) {
        return -1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setTexture(backgroundTexture);

    backgroundSprite.setScale(sf::Vector2f(
        windowWidth / static_cast<float>(backgroundTexture.getSize().x),
        widowHeigth / static_cast<float>(backgroundTexture.getSize().y)
    ));


    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("../../lib/textures/Picsart_25-04-12_05-08-30-636.png")) {
        return -1;
    }

    sf::Texture bulletTexture;
    if (!bulletTexture.loadFromFile("../../lib/textures/Picsart_25-04-12_05-18-42-973.png")) {
        return -1;
    }


    sf::SoundBuffer shoutBuffer;

    if (!shoutBuffer.loadFromFile("../../lib/sounds/deagle.mp3"))
    {
        return -1;
    }

    sf::Sound shout(shoutBuffer);
    shout.setBuffer(shoutBuffer);
    shout.setVolume(35.f);

    sf::SoundBuffer deathBuffer;

    if (!deathBuffer.loadFromFile("../../lib/sounds/death.mp3"))
    {
        return -1;
    }

    sf::Sound death(deathBuffer);
    death.setBuffer(deathBuffer);


    sf::SoundBuffer loseBuffer;

    if (!loseBuffer.loadFromFile("../../lib/sounds/lose.mp3"))
    {
        return -1;
    }

    sf::Sound lose(loseBuffer);
    lose.setBuffer(loseBuffer);

    std::vector<sf::Sprite> bullets;
    std::vector<sf::Sprite> enemies;

    sf::Clock clock;
    sf::Clock bulletTimer;
    sf::Clock enemyTimer;
    
    float tankV = 480.f;
    float bulletV = 500.f;
    float enemyV = 50.f;

    bool isLose =  false;
    bool loseSound = true;
    
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();

        if (!isLose) {
            if (enemyTimer.getElapsedTime().asSeconds() >= 1.5) {
              enemyTimer.restart();

            sf::Sprite enemySprite(enemyTexture);
            enemySprite.setTexture(enemyTexture);

            enemySprite.setOrigin(sf::Vector2f(
                enemyTexture.getSize().x / 2.f,
                enemyTexture.getSize().y / 2.f
            ));

            enemySprite.setScale(sf::Vector2f(
                muzzleWidth * 0.5f / static_cast<float>(tankTexture.getSize().x),
                muzzleWidth * 0.5f / static_cast<float>(tankTexture.getSize().y)
            ));

            enemySprite.setPosition(sf::Vector2f(
                static_cast<float>(getRandomNumber(MD + muzzleWidth * 0.75f / 2, windowWidth - MD - muzzleWidth * 0.75f / 2)),
                0.f
            ));

            enemies.push_back(enemySprite);

            }
        }
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            if (!isLose) {
                if (tankSprite.getPosition().x <= windowWidth - tankWidth)
                    tankSprite.move({tankV * dt, 0.f});
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            if (!isLose) {
                if (tankSprite.getPosition().x >= 0)
                    tankSprite.move({-(tankV * dt), 0.f});
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            if (!isLose) {
                if (bulletTimer.getElapsedTime().asSeconds() >= 0.5f) {
                        bulletTimer.restart();

                        shout.play();

                        sf::Sprite bulletSprite(bulletTexture);
                        bulletSprite.setTexture(bulletTexture);

                        bulletSprite.setOrigin(sf::Vector2f(
                            bulletTexture.getSize().x / 2.f,
                            bulletTexture.getSize().y / 2.f
                        ));

                        bulletSprite.setScale(sf::Vector2f(
                            muzzleWidth / 2.f / static_cast<float>(tankTexture.getSize().x),
                            muzzleWidth / 2.f / static_cast<float>(tankTexture.getSize().y)
                        ));

                        bulletSprite.setPosition(sf::Vector2f(
                            tankSprite.getPosition().x + MD + muzzleWidth / 2.f,
                            tankSprite.getPosition().y
                        ));

                        bullets.push_back(bulletSprite);
                    }
            }
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
        {
            if (isLose) {
                isLose = false;
                loseSound = true;
                score = 0;
                scoreText.setString("SCORE: " + std::to_string(score));
                bullets.clear();
                enemies.clear();
                tankSprite.setPosition(sf::Vector2f(0, widowHeigth - (muzzleHeigth + tankHeigth)));
            }
        }


        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].move(sf::Vector2f(0.f, -(bulletV * dt)));
        }

        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].move(sf::Vector2f(0.f, enemyV * dt));
            if (enemies[i].getPosition().y >= (widowHeigth - tankHeigth - muzzleHeigth - muzzleWidth * 0.75)) {
                isLose = true;
                if (loseSound) {
                    lose.play();
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    loseSound = false;
                }

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
                    death.play();
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
        if(!isLose) {
            window.draw(backgroundSprite);
            window.draw(tankSprite);
            window.draw(scoreText);

            for (int i = 0; i < bullets.size(); i++) {
                window.draw(bullets[i]);
            }
            for (int i = 0; i < enemies.size(); i++) {
                window.draw(enemies[i]);
            }
        } else {
            window.draw(backgroundSprite);
            finishText.setString("YOUR SCORE: " + std::to_string(score) + "\n TO RESTART PRESS R");
            window.draw(finishText);

        }

        window.display();
    }
}