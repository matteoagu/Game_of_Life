#include "game.hpp"

// Private Functions
void Game::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(900,900), "Game of life", sf::Style::Close | sf::Style::Titlebar);
    window->setPosition({800, 0});
    window->setFramerateLimit(144);
    window->setVerticalSyncEnabled(false);
}

void Game::initCells(unsigned int lines, unsigned int columns) {
    Nlines = lines;
    NColumns = columns;
    float stepx = window->getSize().x / columns;
    float stepy = window->getSize().y / lines;
    sf::RectangleShape rect({stepy, stepx});

    rect.setFillColor(sf::Color::White);
    rect.setOutlineThickness(1.f);
    rect.setOutlineColor(sf::Color::Black);

    cells = new Matrix(lines, columns);
    update_cells.setSize(lines, columns);

    if (cells->getLines()!=update_cells.getLines() || cells->getColumns()!=update_cells.getColumns()) {
        throw std::runtime_error{ "FATAL ERROR!" };
    }
    
    for (int i{}; i<lines; i++) {
        for (int j{}; j<columns; j++) {
            rect.setPosition({i * stepy, j * stepx});
            Cell cell(rect);
            cells->insert(cell, i+1, j+1);
            update_cells.insert(cell, i+1, j+1);
        }
    }
}

// Constructor & Destructor
Game::Game() {
    initWindow();
    initCells(25,25);
}

Game::Game(unsigned int lines, unsigned int columns) {
    initWindow();
    initCells(columns, lines);
}

Game::~Game() {
    delete cells;
    delete window;
}

// Functions
void Game::evolve(unsigned int line, unsigned int column) {
    unsigned int n = cells->checkNearby(line+1, column+1);
    bool status = cells->getCell(line, column).getStatus();

    if(status && n<2) {
        update_cells.getCell(line, column).setStatus(false);
        update_cells.getCell(line, column).getCell().setFillColor(sf::Color::White);
    }

    else if(status && n<4) {
        update_cells.getCell(line, column).setStatus(true);
        update_cells.getCell(line, column).getCell().setFillColor(sf::Color::Blue);
    }

    else if(status && n>3) {
        update_cells.getCell(line, column).setStatus(false);
        update_cells.getCell(line, column).getCell().setFillColor(sf::Color::White);
    }

    else if(!status && n==3) {
        update_cells.getCell(line, column).setStatus(true);
        update_cells.getCell(line, column).getCell().setFillColor(sf::Color::Blue);
    }
}

void Game::updatePollEvents() {
    sf::Event ev;
    while(window->pollEvent(ev)) {
        if (ev.Event::type == sf::Event::Closed) { window->close(); }
        if (ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::Escape) { window->close(); }

        if(ev.Event::KeyPressed && ev.Event::key.code == sf::Keyboard::C) {
            for (int i{}; i<cells->getLines(); i++) {
                for (int j{}; j<cells->getColumns(); j++) {
                    cells->getCell(i,j).getCell().setFillColor(sf::Color::White);
                    cells->getCell(i,j).setStatus(false);
                }
            }

            update_cells = *cells;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            for (unsigned int i{}; i<cells->getLines(); i++) {
                for (unsigned int j{}; j<cells->getColumns(); j++) {
                    sf::Vector2f cellPos = cells->getCell(i,j).getCell().getPosition();
                    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                    sf::Vector2f cellSize = cells->getCell(i,j).getCell().getSize();

                    if(mousePos.x > cellPos.x && mousePos.y > cellPos.y && mousePos.x < cellPos.x + cellSize.x && mousePos.y < cellPos.y + cellSize.y &&
                    !cells->getCell(i,j).getStatus()) {
                        cells->getCell(i,j).getCell().setFillColor(sf::Color::Blue);

                        cells->getCell(i,j).setStatus(true);
                    }
                }
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && mouse_clock.restart()>=sf::seconds(0.5f)) {
            if (running) { running = false; }
            else { running = true; }
        }
    }
}

void Game::updateEvolution() {
    if (running && evolution_clock.getElapsedTime()>=sf::seconds(0.2f)) {
        for (unsigned int i{}; i<cells->getLines(); i++) {
            for (unsigned int j{}; j<cells->getColumns(); j++) {
                    this->evolve(i,j);
            }
        }

        *cells = update_cells;
        evolution_clock.restart();
    }
}

void Game::update() {
    updatePollEvents();
    updateEvolution();
}

void Game::render() {
    window->clear();

    for (unsigned int i{}; i<cells->getLines(); i++) {
        for (unsigned int j{}; j<cells->getColumns(); j++) {
            window->draw(cells->getCell(i,j).getCell());
        }
    }

    window->display();
}

void Game::run() {
    while (window->isOpen()) {
        update();
        render();
    }    
}