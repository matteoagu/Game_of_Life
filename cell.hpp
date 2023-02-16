#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Cell {
private:
    sf::RectangleShape cell_;
    bool enlightened_ = false;   // DA CAMBIARE IN FALSE QUANDO FUNZIONERA'

public:
    Cell(sf::RectangleShape);
    Cell();
    virtual ~Cell();

    sf::RectangleShape& getCell();
    bool getStatus();

    void setStatus(bool);
};