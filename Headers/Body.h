//
// Created by root on 15.04.19.
//
#include <SFML/Graphics.hpp>
#include "game_field.h"

#ifndef CONSOLE_SNAKE_BODY_H
#define CONSOLE_SNAKE_BODY_H
class Body {
private:
    sf::RectangleShape* shape;
    float x, y, x_size, y_size, part_size;
    int direction;
    Field* field;
public:
    Body(float x, float y, float x_size, float y_size, int dir, float part_size, Field *f);
    void move_forward();
    void pop_back();
    int get_dir();
    sf::RectangleShape get_shape();
    float get_length();
    float get_x();
    float get_y();
    void move_whole_part();
};
#endif //CONSOLE_SNAKE_BODY_H
