

    #include <SFML/Graphics.hpp>
    #include "ResourcePath.hpp"
    #include <vector>
    #include <cmath>

    int main()
    {
            // Create the main window
            sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

            // Load a sprite to display
            sf::Texture texture;
            if (!texture.loadFromFile(resourcePath() + "graphics/thing.png"))
                    return EXIT_FAILURE;
            sf::Sprite sprite(texture);
            sprite.setOrigin(sprite.getLocalBounds().width / 2,sprite.getLocalBounds().height / 2);
            sprite.setPosition(window.getSize().x / 3,window.getSize().y / 3);

            sf::Texture texObstacle;
            if (!texObstacle.loadFromFile(resourcePath() + "graphics/obstacle.png"))
                    return EXIT_FAILURE;
            sf::Sprite sprObstacle(texObstacle);
            sprObstacle.setOrigin(sprObstacle.getLocalBounds().width / 2,sprObstacle.getLocalBounds().height / 2);

            std::vector<sf::Vector2f> obstacles;
            unsigned countObstacles(6);
            for (unsigned i(0); i < countObstacles; ++ i)
                    for (unsigned j(0); j < 2; ++ j)
                            obstacles.push_back(sf::Vector2f(sprObstacle.getOrigin().x * 2 + sprObstacle.getLocalBounds().width * i,
                                                             sprObstacle.getOrigin().y * 2 + countObstacles * j * sprObstacle.getLocalBounds().height));
            countObstacles *= 2;
            unsigned add(5);
            for (unsigned i(0); i < add; ++ i)
                    for (unsigned j(0); j < 2; ++ j)
                            obstacles.push_back(sf::Vector2f(sprObstacle.getOrigin().x * 2 + add * j * sprObstacle.getLocalBounds().width,
                                                             sprObstacle.getOrigin().y * 4 + sprObstacle.getLocalBounds().height * i));
            countObstacles += add * 2;

            const float speed(100.f);
            sf::Clock clock;

            // Start the game loop
            while (window.isOpen())
            {
                    // Process events
                    sf::Event event;
                    while (window.pollEvent(event))
                    {
                            // Close window : exit
                            if (event.type == sf::Event::Closed)
                                    window.close();

                            // Escape pressed : exit
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                                    window.close();
                    }

                    // Clear screen
                    window.clear(sf::Color::White);

                    const double dt(clock.restart().asSeconds());

                    bool movedLeft(false), movedRight(false), movedUp(false), movedDown(false);

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                     {
                            sprite.move(-speed * dt,.0f);
                            movedLeft = true;
                     }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                     {
                            sprite.move(speed * dt,.0f);
                            movedRight = true;
                     }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                     {
                            sprite.move(.0f,-speed * dt);
                            movedUp = true;
                     }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                     {
                            sprite.move(.0f,speed * dt);
                            movedDown = true;
                     }

                    for (unsigned i(0); i < countObstacles; ++ i)
                     {
                            sprObstacle.setPosition(obstacles[i]);
                            window.draw(sprObstacle);

                            // COLLISION CODE STARTS HERE

                            const sf::Vector2f op(sprObstacle.getPosition()),
                                               sp(sprite.getPosition());
                            const float ow(sprObstacle.getLocalBounds().width / 2),
                                        sw(sprite.getLocalBounds().width / 2),
                                                    oh(sprObstacle.getLocalBounds().height / 2),
                                                    sh(sprite.getLocalBounds().height / 2),
                                                    distx(std::abs(sp.x - op.x)),
                                            disty(std::abs(sp.y - op.y));

                            if (sprite.getGlobalBounds().intersects(sprObstacle.getGlobalBounds()))
                             {
                                    if (movedLeft || movedRight)
                                     {
                                            if (!((movedUp || movedDown) && disty > distx))
                                             {
                                                    if (sp.x >= op.x)
                                                            sprite.setPosition(op.x + ow + sw,sprite.getPosition().y);
                                                    else
                                                            sprite.setPosition(op.x - ow - sw,sprite.getPosition().y);
                                             }
                                     }
                             }

                            if (sprite.getGlobalBounds().intersects(sprObstacle.getGlobalBounds()))
                             {
                                    if (movedUp || movedDown)
                                     {
                                            if (!((movedLeft || movedRight) && distx > disty))
                                             {
                                                    if (sp.y >= op.y)
                                                            sprite.setPosition(sprite.getPosition().x,op.y + oh + sh);
                                                    else
                                                            sprite.setPosition(sprite.getPosition().x,op.y - oh - sh);
                                             }
                                     }
                             }

                            // COLLISION CODE ENDS HERE
                     }

                    // Draw the sprite
                    window.draw(sprite);

                    // Update the window
                    window.display();
            }

            return EXIT_SUCCESS;
    }


