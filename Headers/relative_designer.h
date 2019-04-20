//
// Created by root on 11.04.19.
//

#ifndef CONSOLE_SNAKE_RELATIVE_DESIGNER_H
#define CONSOLE_SNAKE_RELATIVE_DESIGNER_H
class Relative_Designer {
private:
    float one_x_percent, one_y_percent;
    float calculate_one_percent(int num);
    int window_size_x, window_size_y;
public:
    Relative_Designer(int x, int y);
    int get_window_size_x();
    int get_window_size_y();
    float calculate_actual_x(float percentage);
    float calculate_actual_y(float percentage);
};
#endif //CONSOLE_SNAKE_RELATIVE_DESIGNER_H
