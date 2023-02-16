#include "cell.hpp"

Cell::Cell(sf::RectangleShape rect) {
    cell_ = rect;
}

Cell::Cell() {
}

Cell::~Cell() {
}

sf::RectangleShape& Cell::getCell() {
    return cell_;
}

bool Cell::getStatus() {
    return enlightened_;
}

void Cell::setStatus(bool status) {
    enlightened_ = status;
}