//
// Created by root on 11.04.19.
//

#include "../Headers/relative_designer.h"
Relative_Designer::Relative_Designer(int x, int y) {
    this->window_size_x = x;
    this->window_size_y = y;
    this->one_x_percent = calculate_one_percent(x);
    this->one_y_percent = calculate_one_percent(y);
}

float Relative_Designer::calculate_one_percent(int num) {
    return num / 100.f;
}

float Relative_Designer::calculate_actual_x(float percentage) {
    return this->one_x_percent * percentage;
}

float Relative_Designer::calculate_actual_y(float percentage) {
    return this->one_y_percent * percentage;
}

int Relative_Designer::get_window_size_x() {
    return this->window_size_x;
}

int Relative_Designer::get_window_size_y() {
    return this->window_size_y;
}