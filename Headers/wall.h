//
// Created by root on 11.04.19.
//

#include "relative_designer.h"
#include <SFML/Graphics.hpp>

#ifndef CONSOLE_SNAKE_WALL_H
#define CONSOLE_SNAKE_WALL_H
class Wall {
private:
    float x, y, dimension;
    sf::RectangleShape* shape;
public:
    explicit Wall(float x, float y, float width, float height);
    float get_wall_dimension();
    sf::RectangleShape get_shape();
    float get_x();
    float get_y();
};
#endif //CONSOLE_SNAKE_WALL_H
