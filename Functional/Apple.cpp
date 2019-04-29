//
// Created by root on 22.04.19.
//

#include "../Headers/Apple.h"

Apple::Apple(sf::RenderWindow *w, const std::string &file_path, float x, float y, float width, bool bad) {
    this->window = w;
    this->texture = new sf::Texture;
    this->texture->loadFromFile(file_path);
    this->texture->setSmooth(true);
    this->shape = new sf::RectangleShape;
    this->shape->setTexture(this->texture);
    this->shape->setPosition(x, y);
    this->shape->setSize(sf::Vector2f(width, width));
    this->x = x;
    this->y = y;
    this->size = width;
    this->bad = bad;
}

sf::RectangleShape Apple::get_shape() {
    return *this->shape;
}

float Apple::get_x() {
    return this->x;
}

float Apple::get_y() {
    return this->y;
}

float Apple::get_size() {
    return this->size;
}