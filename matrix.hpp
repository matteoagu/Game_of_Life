#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <iostream>

#include "cell.hpp"

class Matrix {
private:
    std::vector<std::vector<Cell>> matrix;
    unsigned int lines_;
    unsigned int columns_;

    // Private functions


public:
    Matrix();
    Matrix(unsigned int, unsigned int);
    virtual ~Matrix();

    // Functions
    unsigned int const getLines();
    unsigned int const getColumns();
    Cell& getCell(unsigned int, unsigned int);

    void const setSize(unsigned int, unsigned int);
    void const fullFill(Cell);
    void const insert(Cell, unsigned int, unsigned int);

    unsigned int const checkNearby(unsigned int, unsigned int);
};