//
// Created by root on 15.04.19.
//

#include "../Headers/Body.h"

Body::Body(float x, float y, float x_size, float y_size, int dir, float part_size) {
    this->x = x;
    this->y = y;
    this->x_size = x_size;
    this->y_size = y_size;
    this->direction = dir;
    this->part_size = part_size;
    this->shape = new sf::RectangleShape(sf::Vector2f(x_size, y_size));
    this->shape->setFillColor(sf::Color::Blue);
    this->shape->setPosition(x, y);
}

void Body::move_forward() {
    switch (this->direction) {
        case 1: {
            this->y -= this->part_size;
            this->y_size += this->part_size;
            this->shape->setPosition(this->x, this->y);
            this->shape->setSize(sf::Vector2f(this->x_size, this->y_size));
            break;
        }
        case -1: {
            this->y_size += this->part_size;
            this->shape->setSize(sf::Vector2f(this->x_size, this->y_size));
            break;
        }
        case 2: {
            this->x_size += this->part_size;
            this->shape->setSize(sf::Vector2f(this->x_size, this->y_size));
            break;
        }
        case -2: {
            this->x -= this->part_size;
            this->x_size += this->part_size;
            this->shape->setPosition(this->x, this->y);
            this->shape->setSize(sf::Vector2f(this->x_size, this->y_size));
            break;
        }
    }
}

void Body::pop_back() {
    switch (this->direction) {
        case 1: {
            this->y_size -= this->part_size;
            this->shape->setSize(sf::Vector2f(this->x_size, this->y_size));
            break;
        }
        case -1: {
            this->y += this->part_size;
            this->y_size -= this->part_size;
            this->shape->setPosition(this->x, this->y);
            this->shape->setSize(sf::Vector2f(this->x_size, this->y_size));
            break;
        }
        case 2: {
            this->x += this->part_size;
            this->x_size -= this->part_size;
            this->shape->setPosition(this->x, this->y);
            this->shape->setSize(sf::Vector2f(this->x_size, this->y_size));
            break;
        }
        case -2: {
            this->x_size -= this->part_size;
            this->shape->setSize(sf::Vector2f(this->x_size, this->y_size));
            break;
        }
    }
}

int Body::get_dir() {
    return this->direction;
}

float Body::get_length() {
    if (this->direction == 1 || this->direction == -1) return this->y_size;
    else return x_size;
}

sf::RectangleShape Body::get_shape() {
    return *this->shape;
}

float Body::get_x() {
    return this->x;
}

float Body::get_y() {
    return this->y;
}

void Body::move_whole_part() {
    switch (this->direction) {
        case 1: {
            this->y -= this->part_size;
            break;
        }
        case -1: {
            this->y += this->part_size;
            break;
        }
        case 2: {
            this->x += this->part_size;
            break;
        }
        case -2: {
            this->x -= this->part_size;
            break;
        }
        default:
            break;
    }
    this->shape->setPosition(this->x, this->y);
}