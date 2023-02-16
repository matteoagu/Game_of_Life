#include "game.hpp"

#include <time.h>
#include <iostream>

int main() {

    // HOW TO USE
    std::cout << "Welcome in Game of Life, a free-to-play game that simulates the evolution of life on a 50x50 board.\n\nHOW TO USE:\n" <<
        "- Left button: on a cell, makes it alive\n" <<
        "- Right button (when the game is not running): starts the game\n" <<
        "- Right button (when the game is running): stops the game\n" <<
        "- C button on keyboard (in every moment): kills all the cells\n\n\n" <<
        "Enjoy!\n\n";

    Game game(50,50);

    game.run();

    std::cout << "Thanks for playing!\n\n\n";
}