#include "matrix.hpp"

Matrix::Matrix() {
}

Matrix::Matrix(unsigned int lines, unsigned int columns) {
    lines_ = lines;
    columns_ = columns;

    for (int i{}; i<lines; i++) {
        matrix.push_back(std::vector<Cell>());

        for (int j{}; j<columns; j++) {
            matrix[i].push_back(Cell());
        }
    }
}

Matrix::~Matrix() {
}

// Functions
unsigned int const Matrix::getLines() { return lines_; }

unsigned int const Matrix::getColumns() { return columns_; }

Cell& Matrix::getCell(unsigned int line, unsigned int column) {
    return matrix[line][column];
}

void const Matrix::setSize(unsigned int lines, unsigned int columns) {
    lines_ = lines;
    columns_ = columns;
    matrix.clear();

    for (int i{}; i<lines; i++) {
        matrix.push_back(std::vector<Cell>());

        for (int j{}; j<columns; j++) {
            matrix[i].push_back(Cell());
        }
    }
}

void const Matrix::fullFill(Cell cell) {
    for (int i{}; i<lines_; i++) {
        for (int j{}; j<columns_; j++) {
            matrix[i][j] = cell;
        }
    }
}

void const Matrix::insert(Cell cell, unsigned int line, unsigned int column) {  // Inserire i numeri partendo a contare da 1 e non da 0!
    matrix[line-1][column-1] = cell;
}

unsigned int const Matrix::checkNearby(unsigned int line, unsigned int column) {    // Inserire i numeri partendo a contare da 1 e non da 0!
    unsigned int number{};

    for (int i{-1}; i<2; i++) {
        for (int j{-1}; j<2; j++) {
            if (line!=1 && line!=lines_ && column!=1 && column!=columns_) {     //celle centrali
                if (i==0 && j==0) {}

                else {
                    if (matrix[line+i-1][column+j-1].getStatus()) { number++; }
                }
            }

            else if (line!=1 && line!=lines_) {
                if (column==1) {                                                //righe centrali e prima colonna
                    if (j==-1 || (i==0 && j==0)) {}

                    else {
                        if (matrix[line+i-1][column+j-1].getStatus()) { number++; }
                    }
                }

                else {                                                          //righe centrali e ultima colonna
                    if (j==1 || (i==0 && j==0)) {}

                    else {
                        if (matrix[line+i-1][column+j-1].getStatus()) { number++; }
                    }
                }
            }

            else if (column!=1 && column!=columns_) {
                if (line==1) {                                                //colonne centrali e prima riga
                    if (i==-1 || (i==0 && j==0)) {}

                    else {
                        if (matrix[line+i-1][column+j-1].getStatus()) { number++; }
                    }
                }

                else {                                                          //colonne centrali e ultima riga
                    if (i==1 || (i==0 && j==0)) {}

                    else {
                        if (matrix[line+i-1][column+j-1].getStatus()) { number++; }
                    }
                }
            }

            else {
                if (line == 1 && column==1) {                                   //top left corner
                    if ((i==-1 || j==-1) || (i==0 && j==0)) {}                  

                    else {
                        if (matrix[line+i-1][column+j-1].getStatus()) { number++; }
                    }
                }

                else if (line == 1 && column==columns_) {                       //top right corner
                    if ((i==-1 || j==1) || (i==0 && j==0)) {}                  

                    else {
                        if (matrix[line+i-1][column+j-1].getStatus()) { number++; }
                    }
                }

                else if (line == lines_ && column==1) {                         //bottom left corner
                    if ((i==1 || j==-1) || (i==0 && j==0)) {}                  

                    else {
                        if (matrix[line+i-1][column+j-1].getStatus()) { number++; }
                    }
                }

                else if (line == lines_ && column==columns_) {                  //bottom right corner
                    if ((i==1 || j==1) || (i==0 && j==0)) {}                  

                    else {
                        if (matrix[line+i-1][column+j-1].getStatus()) { number++; }
                    }
                }
            }
        }
    }

    return number;
}