//
// Created by root on 12.04.19.
//

#ifndef CONSOLE_SNAKE_SNAKE_H
#define CONSOLE_SNAKE_SNAKE_H

#include <SFML/Graphics.hpp>
#include <deque>
#include "relative_designer.h"
#include "game_field.h"
#include "Logs.h"
#include "Body.h"

//==============
//| Table of directions
//| 1 -> up
//| 2 -> right
//| -1 -> down
//| -2 -> left
//==============
class Snake {
private:
    sf::RenderWindow* window;
    Relative_Designer* designer;
    Field* field;
    float size_of_body_part;
    float size;
    int movement_set[4] = {1, 2, -1, -2};
    int current_direction = 2;
    bool is_move_available(int want_to_go);
    bool is_alive = true;
    Log* log;
    std::deque<Body*> parts;
    void is_snake_bite_yourself();
public:
    Snake(float initial_size, sf::RenderWindow* window, Relative_Designer *des, Field *f, Log *log);
    void draw();
    void move();
    void confuse_movement();
    void go_up();
    void go_down();
    void go_left();
    void go_right();
};
#endif //CONSOLE_SNAKE_SNAKE_H
