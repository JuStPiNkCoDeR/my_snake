//
// Created by root on 11.04.19.
//

#include "../Headers/wall.h"

Wall::Wall(float size) {
    this->dimension = size;
}

float Wall::get_wall_dimension() {
    return this->dimension;
}