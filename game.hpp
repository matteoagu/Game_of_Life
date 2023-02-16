#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "matrix.hpp"

class Game {
private:
    sf::RenderWindow* window;
    sf::Clock mouse_clock;
    sf::Clock evolution_clock;

    unsigned int Nlines;
    unsigned int NColumns;
    bool running = false;

    Matrix* cells;
    Matrix update_cells;

    // Private Functions
    void initWindow();
    void initCells(unsigned int, unsigned int);

public:
    Game();
    Game(unsigned int, unsigned int);
    virtual ~Game();

    // Functions
    void evolve(unsigned int, unsigned int);
    void updatePollEvents();
    void updateEvolution();

    void update();
    void render();
    void run();
};