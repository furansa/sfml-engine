#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <string>
#include <SFML/Graphics.hpp>

class Window {
public:
    Window();
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    ~Window();

    void beginDraw();
    void endDraw();
    void update();
    bool isDone();
    bool isFullscreen();
    void toggleFullscreen();
    sf::Vector2u getWindowSize();
    void draw(sf::Drawable& l_drawable);

private:
    void setup(const std::string& l_title, const sf::Vector2u& l_size);
    void create();
    void destroy();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;
};
#endif