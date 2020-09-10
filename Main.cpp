#include "Game.hpp"

int main() {
    // Program entry point
    Game game;

    while(!game.getWindow()->isDone()) {
        // Game loop
        game.handleInput();
        game.update();
        game.render();
        //sf::sleep(sf::seconds(0.2)); // Sleep for 0.2 seconds, only for testing
        game.restartClock(); // Restart game clock after each interaction
    }

    return(0);
}