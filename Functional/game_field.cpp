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
    this->window->draw(this->apple->get_shape());
    for (auto & wall : this->walls) {
        this->window->draw(wall->get_shape());
    }
}

void Field::gen_new_apple(int size_of_snake) {
    delete this->apple;
    srandom(std::time(nullptr));
    const int num = 5;
    int multiplier = size_of_snake / 2;
    int range = num * multiplier;
    int res = random() % 100;

    float x, y;
    int max_steps_for_x, max_steps_for_y;
    max_steps_for_x = static_cast<int>(this->field_size_x / this->one_step);
    max_steps_for_y = static_cast<int>(this->field_size_y / this->one_step);
    float res_x = random() % (max_steps_for_x + 1);
    float res_y = random() % (max_steps_for_y + 1);
    x = this->get_border_coord(-2) + (res_x * this->one_step);
    y = this->get_border_coord(1) + (res_y * this->one_step);
    if (res > 0 && res <= range) this->apple = new Apple(this->window, "../Textures/simple_apple.jpg", x, y, this->one_step, true);
    else this->apple = new Apple(this->window, "../Textures/simple_apple.jpg", x, y, this->one_step);
}

Apple* Field::get_apple() {
    return this->apple;
}