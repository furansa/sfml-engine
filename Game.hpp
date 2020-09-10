#ifndef GAME_HPP
#define GAME_HPP
#include "Window.hpp"

class Game {
public:
    Game();
    ~Game();

    void handleInput();
    void update();
    void render();
    Window* getWindow();
    sf::Time getElapsed();
    void restartClock();

private:
    void move();
    Window m_window;
    sf::Texture m_playerTexture;
    sf::Sprite m_playerSprite;
    sf::Vector2i m_increment;
    sf::Clock m_clock;
    sf::Time m_elapsed;
};
#endif