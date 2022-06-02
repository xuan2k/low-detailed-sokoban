#include "game.h"
#include "constant.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Low-detailed-sokoban"), player(), level() 
{
    // window.setKeyRepeatEnabled(false);
    // window.setFramerateLimit(100);
    // sf::Font font;
    if (!font.loadFromFile("assets/font/arial.ttf"))
        std::cout << "font can't be loaded\n";

    title.setFont(font);
    title.setFillColor(sf::Color(255, 88, 74));
    title.setOutlineColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setCharacterSize(32);
    title.setPosition(0, 0);
    
}

void Game::processEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
            {
                level.try2Move(Direction::UP);
                player.setDirection(sf::Vector2f(0.0, -1.0));
                player.setSprite(Direction::UP);
            }
            else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
            {
                level.try2Move(Direction::DOWN);
                player.setDirection(sf::Vector2f(0.0, 1.0));
                player.setSprite(Direction::DOWN);
            }
            else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
            {
                level.try2Move(Direction::LEFT);
                player.setDirection(sf::Vector2f(-1.0, 0.0));
                player.setSprite(Direction::LEFT);
            }
            else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
            {
                level.try2Move(Direction::RIGHT);
                player.setDirection(sf::Vector2f(1.0, 0.0));
                player.setSprite(Direction::RIGHT);
            }
        }
        // else if (event.type = sf::Event::KeyReleased)
        //     continue;
    }
}

void Game::update()
{
    level.update();
    player.update(level);
}

void Game::render()
{
    window.clear(sf::Color(55, 138, 138, 1));

    window.draw(title);
    window.draw(level);
    window.draw(player);

    window.display();
}

void Game::run()
{   
    for (int l = 1; l <= LEVEL_NUM; l++)
    {
        level.loadLevel(l);

        title.setString("LEVEL " + std::to_string(l));

        sf::Vector2u board_size = level.getSize();
        float posx_board = WINDOW_WIDTH / 2 - board_size.x / 2.0f;
        float posy_board = WINDOW_HEIGHT / 2 - board_size.y / 2.0f;
        player.setOrigin(posx_board, posy_board);
        sf::Vector2u player_position = level.getPlayerPosition();
        player.setPosition(player_position);

        while (window.isOpen())
        {
            processEvents();
            update();
            render();

            if (level.isFinished())
            {
                std::cout << "Level " << l << " completed >:D\n";
                break;
            }
        }
    }
}