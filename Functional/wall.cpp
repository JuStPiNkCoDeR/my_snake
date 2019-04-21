//
// Created by root on 11.04.19.
//

#include "../Headers/wall.h"

Wall::Wall(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    if (width > height) this->dimension = height;
    else this->dimension = width;
    this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
    this->shape->setPosition(x, y);
    this->shape->setFillColor(sf::Color::White);
}

float Wall::get_wall_dimension() {
    return this->dimension;
}

sf::RectangleShape Wall::get_shape() {
    return *this->shape;
}

float Wall::get_x() {
    return this->x;
}

float Wall::get_y() {
    return this->y;
}