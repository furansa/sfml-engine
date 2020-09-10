#include "Window.hpp"

/* 
 * @brief   Default constructor
 * @returns A instance of the class
 */
Window::Window() { setup("Window", sf::Vector2u(640, 480)); }

/* 
 * @brief   Constructor
 * @param   l_title Window object title
 * @param   l_size Window object size
 * @returns A instance of the class
 */
Window::Window(const std::string& l_title, const sf::Vector2u& l_size) {
    setup(l_title, l_size);
}

/* 
 * @brief   Destructor
 */
Window::~Window() { destroy(); }

/* 
 * @brief   Clears the screen and fills with a given color
 */
void Window::beginDraw() { m_window.clear(sf::Color::Black); }

/* 
 * @brief   Displays on the screen what has been rendered so far
 */
void Window::endDraw() { m_window.display(); }

/*
 * @brief   Processes the events of the Window
 */
void Window::update() {
    sf::Event event;

    while(m_window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) { // Check if the Window was closed
            m_isDone = true;
        } else if(event.type == sf::Event::KeyPressed && 
            event.key.code == sf::Keyboard::F5) { // Check if F5 was pressed
            toggleFullscreen();
        }
    }
}

/*
 * @brief   Helper getter method
 * @returns m_isDone
 */
bool Window::isDone() { return(m_isDone); }

/*
 * @brief   Helper getter method
 * @returns m_isFullscreen
 */
bool Window::isFullscreen() { return(m_isFullscreen); }

/*
 * @brief   Toogles fullscreen Window state
 */
void Window::toggleFullscreen() {
    m_isFullscreen = !m_isFullscreen;
    // Destroy and recreate the Window in order to apply the changes 
    destroy();
    create();
}

/*
 * @brief   Helper getter method
 * @returns m_windowSize
 */
sf::Vector2u Window::getWindowSize() { return(m_windowSize); }

/*
 * @brief   Draws a object to a target Window
 * @param   l_drawable A drawable object
 */
void Window::draw(sf::Drawable& l_drawable) {
    m_window.draw(l_drawable);
}

/*
 * @brief   Initializes and keeps track of Window properties, calls create()
 * @param   l_title Window object title
 * @param   l_size Window object size
 */
void Window::setup(const std::string& l_title, const sf::Vector2u& l_size) {
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    create();
}

/*
 * @brief   Creates a new Window based on already defined properties
 */
void Window::create() {
    auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, style);
}

/*
 * @brief   Destroy a existing Window instance
 */
void Window::destroy() { m_window.close(); }