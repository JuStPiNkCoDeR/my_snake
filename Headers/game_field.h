//
// Created by root on 11.04.19.
//

#include "relative_designer.h"
#include "wall.h"
#include "Logs.h"
#include "Apple.h"
#include <SFML/Graphics.hpp>

#ifndef CONSOLE_SNAKE_GAME_FIELD_H
#define CONSOLE_SNAKE_GAME_FIELD_H

//TODO("Яблочки")
class Field {
private:
    float field_size_x, field_size_y, one_step;
    std::vector<Wall*> walls;
    Relative_Designer* designer;
    sf::RenderWindow* window;
    Log* log;
    Apple* apple;
public:
    Field(float x, float y, sf::RenderWindow *w, Relative_Designer *des, Log *l);
    float get_field_size_x();
    float get_field_size_y();
    float get_one_step();
    float get_border_coord(int dir);
    void draw();
    void gen_new_apple(int size_of_snake);
    Apple* get_apple();
};
#endif //CONSOLE_SNAKE_GAME_FIELD_H
