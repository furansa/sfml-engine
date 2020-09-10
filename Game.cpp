#include "Game.hpp"

/* 
 * @brief   Default constructor
 * @returns A instance of the class
 */
Game::Game():m_window("Game", sf::Vector2u(800, 600)) {
    // Setup class members
    m_playerTexture.loadFromFile("../assets/Eye.png");
    m_playerSprite.setTexture(m_playerTexture);
    m_increment = sf::Vector2i(400, 400); // The sprite will move 400 pixels a second
}

/* 
 * @brief   Destructor
 */
Game::~Game() {}

/* 
 * @brief   Descriptive text about the class, method, function or whatever
 * @param   l_paramName1 The first parameter with description if necessary
 * @param   l_paramName2 The second parameter with description if necessary
 * @returns Descriptive text about the return if exists
 * @throws  myException if exists, with description if necessary
 */
void Game::handleInput() {}

/* 
 * @brief   Updates Window events and movements the player
 */
void Game::update() {
    m_window.update();
    move();
}

/* 
 * @brief   Draws the sprite to the screen
 */
void Game::render() {
    m_window.beginDraw(); // Clear the window
    m_window.draw(m_playerSprite); // Draw the object
    m_window.endDraw(); // Display
}

/* 
 * @brief   Helper getter method
 * @returns m_window
 */
Window* Game::getWindow() { return(&m_window); }

/* 
 * @brief   Helper getter method
 * @returns m_elapsed
 */
sf::Time Game::getElapsed() { return(m_elapsed); }

/* 
 * @brief   Updates the elapsed time for the Clock object and restart it
 */
void Game::restartClock() { m_elapsed = m_clock.restart(); }

/* 
 * @brief   Updates the sprite's position
 */
void Game::move() {
    sf::Vector2u l_windowSize = m_window.getWindowSize();
    sf::Vector2u l_textureSize = m_playerTexture.getSize();
    float elapsedSeconds = m_elapsed.asSeconds(); // Time passed during the previous interaction

    if((m_playerSprite.getPosition().x > l_windowSize.x - l_textureSize.x && 
        m_increment.x > 0) || (m_playerSprite.getPosition().x < 0 && m_increment.x < 0)) {
        m_increment.x = -m_increment.x;
    }

    if((m_playerSprite.getPosition().y > l_windowSize.y - l_textureSize.y && 
        m_increment.y > 0) || (m_playerSprite.getPosition().y < 0 && m_increment.y < 0)) {
        m_increment.y = -m_increment.y;
    }

    // Move the sprite across the screen using increment as a variable of speed,
    // distance = speed x time
    m_playerSprite.setPosition(
        (m_playerSprite.getPosition().x + (m_increment.x * elapsedSeconds)), 
        (m_playerSprite.getPosition().y + (m_increment.y * elapsedSeconds)));
}