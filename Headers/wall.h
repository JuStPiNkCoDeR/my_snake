//
// Created by root on 11.04.19.
//

#ifndef CONSOLE_SNAKE_WALL_H
#define CONSOLE_SNAKE_WALL_H

#include "relative_designer.h"

class Wall {
private:
    float dimension;
public:
    explicit Wall(float size);
    float get_wall_dimension();
};
#endif //CONSOLE_SNAKE_WALL_H
