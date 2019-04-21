//
// Created by root on 11.04.19.
//

#include "../Headers/game_field.h"
#include "../Headers/wall.h"
#include "../Headers/Logs.h"
#include <SFML/Graphics.hpp>

Field::Field(float x, float y, sf::RenderWindow *w, Relative_Designer *des, Log *l) {
    this->window = w;
    this->log = l;
    walls.push_back(new Wall(0.f, 0.f, x, des->calculate_actual_y(3.f))); // top
    walls.push_back(new Wall(0.f, 0.f, des->calculate_actual_x(3.f), y)); // left
    walls.push_back(new Wall(0.f, des->calculate_actual_y(97.f), x, des->calculate_actual_y(3.f))); // bottom
    walls.push_back(new Wall(des->calculate_actual_x(97.f), 0.f, des->calculate_actual_x(3.f), y)); // right
    this->field_size_x = x - (2 * des->calculate_actual_x(3.f));
    this->field_size_y = y - (2 * des->calculate_actual_y(3.f));
    this->designer = des;
    this->one_step = x / 100;
}

float Field::get_field_size_x() {
    return this->field_size_x;
}

float Field::get_field_size_y() {
    return this->field_size_y;
}

float Field::get_one_step() {
    return this->one_step;
}

float Field::get_border_coord(int dir) {
    switch (dir) {
        case 2: {
            return this->walls[3]->get_x();
        }
        case -2: {
            return this->walls[1]->get_x() + this->walls[1]->get_wall_dimension();
        }
        case 1: {
            return this->walls[0]->get_y() + this->walls[0]->get_wall_dimension();
        }
        case -1: {
            return this->walls[2]->get_y();
        }
        default:
            return 0.f;
    }
}

void Field::draw() {
    for (auto & wall : this->walls) {
        this->window->draw(wall->get_shape());
    }
}