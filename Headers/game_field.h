//
// Created by root on 11.04.19.
//

#ifndef CONSOLE_SNAKE_GAME_FIELD_H
#define CONSOLE_SNAKE_GAME_FIELD_H

#include "relative_designer.h"

class Field {
private:
    float field_size_x, field_size_y, dimension, one_step;
    Relative_Designer* designer;
public:
    Field(float x, float y, float d, Relative_Designer *des);
    float get_field_size_x();
    float get_field_size_y();
    float get_one_step();
    float get_dimension();
};
#endif //CONSOLE_SNAKE_GAME_FIELD_H
