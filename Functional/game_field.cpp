//
// Created by root on 11.04.19.
//

#include "../Headers/game_field.h"
#include <SFML/Graphics.hpp>

Field::Field(float x, float y, float d, Relative_Designer *des) {
    this->field_size_x = x - 2*d;
    this->field_size_y = y - 2*d;
    this->dimension = d;
    this->designer = des;
    this->one_step = this->field_size_x / 100;
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

float Field::get_dimension() {
    return this->dimension;
}