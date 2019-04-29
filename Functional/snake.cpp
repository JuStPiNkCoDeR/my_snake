//
// Created by root on 12.04.19.
//

#include <iostream>
#include <future>
#include "../Headers/snake.h"
#include "../Headers/Logs.h"
#include "../Headers/Body.h"

Snake::Snake(int initial_size, sf::RenderWindow* window, Relative_Designer *des, Field *f, Log *log) {
    this->log = log;
    this->designer = des;
    this->field = f;
    this->size = initial_size;
    this->size_of_body_part = this->field->get_one_step();
    float x = this->field->get_border_coord(-2) + ((50 - initial_size) * this->field->get_one_step());
    float y = this->field->get_border_coord(1) + (50 * this->field->get_one_step());
    this->window = window;
    this->parts.push_back(new Body(x, y, this->field->get_one_step() * initial_size, this->field->get_one_step(), this->current_direction, this->size_of_body_part, f));
    this->field->gen_new_apple(this->size);
}

void Snake::move() {
    if (this->is_alive) {
        try {
            if (this->parts.size() > 1) {
                this->parts.at(0)->move_forward();
                is_snake_bite_yourself();
                if (!this->is_eat_apple()) {
                    this->parts.back()->pop_back();
                } else {
                    this->size++;
                    this->field->gen_new_apple(this->size);
                }
                if (this->parts.back()->get_length() < this->size_of_body_part) {
                    this->parts.pop_back();
                }
            } else {
                this->parts.at(0)->move_whole_part();
                if (this->is_eat_apple()) {
                    this->size++;
                    this->field->gen_new_apple(this->size);
                    this->parts.at(0)->move_forward();
                }
            }
        } catch (int &e) {
            this->is_alive = false;
            this->log->reset_text("DIED!!!");
        }
    }
}

void Snake::draw() {
    this->window->draw(this->log->getText());
    for (auto & part : this->parts) {
        this->window->draw(part->get_shape());
    }
}

void Snake::confuse_movement() {
    this->log->reset_text("I'm confused!!!");
    srandom(std::time(nullptr));
    int res = -3 + random() % (4 + 3);
    int new_array[4];

    for (int i = 0; i < 4; i++) {
        int new_index = i + res;
        if (new_index > 3) new_index -= 4;
        if (new_index < 0) new_index = 4 - (new_index * -1);
        new_array[new_index] = this->movement_set[i];
    }

    for (int i = 0; i < 4; i++) {
        this->movement_set[i] = new_array[i];
    }
}

bool Snake::is_move_available(int want_to_go) {
    return this->current_direction * -1 != want_to_go && this->current_direction != want_to_go && this->parts.front()->get_length() > 0.f;
}

void Snake::go_up() {
    int task_direction = this->movement_set[0];
    if (this->is_move_available(task_direction)) {
        this->current_direction = task_direction;
        Body* prev_part = this->parts[0];
        float x, y;
        if (prev_part->get_dir() == 2) {
            x = prev_part->get_x() + (prev_part->get_length() - this->size_of_body_part);
            y = prev_part->get_y();
            this->parts.push_front(new Body(x, y, this->size_of_body_part, 0.f,
                                            this->current_direction, this->size_of_body_part, this->field));
        } else {
            x = prev_part->get_x();
            y = prev_part->get_y();
            this->parts.push_front(new Body(x, y, this->size_of_body_part, 0.f,
                                            this->current_direction, this->size_of_body_part, this->field));
        }
    }
}

void Snake::go_right() {
    int task_direction = this->movement_set[1];
    if (this->is_move_available(task_direction)) {
        this->current_direction = task_direction;
        Body* prev_part = this->parts[0];
        float x, y;
        if (prev_part->get_dir() == 1) {
            x = prev_part->get_x() + this->size_of_body_part;
            y = prev_part->get_y();
            this->parts.push_front(new Body(x, y, 0.f, this->size_of_body_part,
                                            this->current_direction, this->size_of_body_part, this->field));
        } else {
            x = prev_part->get_x();
            y = prev_part->get_y() + (prev_part->get_length() - this->size_of_body_part);
            this->parts.push_front(new Body(x, y, 0.f, this->size_of_body_part,
                                            this->current_direction, this->size_of_body_part, this->field));
        }
    }
}

void Snake::go_down() {
    int task_direction = this->movement_set[2];
    if (this->is_move_available(task_direction)) {
        this->current_direction = task_direction;
        Body* prev_part = this->parts[0];
        float x, y;
        if (prev_part->get_dir() == 2) {
            x = prev_part->get_x() + (prev_part->get_length() - this->size_of_body_part);
            y = prev_part->get_y() + this->size_of_body_part;
            this->parts.push_front(new Body(x, y, this->size_of_body_part, 0.f,
                                            this->current_direction, this->size_of_body_part, this->field));
        } else {
            x = prev_part->get_x();
            y = prev_part->get_y() + this->size_of_body_part;
            this->parts.push_front(new Body(x, y, this->size_of_body_part, 0.f,
                                            this->current_direction, this->size_of_body_part, this->field));
        }
    }
}

void Snake::go_left() {
    int task_direction = this->movement_set[3];
    if (this->is_move_available(task_direction)) {
        this->current_direction = task_direction;
        Body* prev_part = this->parts[0];
        float x, y;
        if (prev_part->get_dir() == 1) {
            x = prev_part->get_x();
            y = prev_part->get_y();
            this->parts.push_front(new Body(x, y, 0.f, this->size_of_body_part,
                                            this->current_direction, this->size_of_body_part, this->field));
        } else {
            x = prev_part->get_x();
            y = prev_part->get_y() + (prev_part->get_length() - this->size_of_body_part);
            this->parts.push_front(new Body(x, y, 0.f, this->size_of_body_part,
                                            this->current_direction, this->size_of_body_part, this->field));
        }
    }
}

void Snake::is_snake_bite_yourself() {
    if (this->current_direction == 2 || this->current_direction == -2) {
        for (int i = 2; i < this->parts.size(); i++) {
            if (this->parts[i]->get_dir() == 1 || this->parts[i]->get_dir() == -1) {
                if ((this->parts.at(0)->get_x() + this->parts.at(0)->get_length() > this->parts[i]->get_x() && this->parts.at(0)->get_x() <= this->parts[i]->get_x() + this->size_of_body_part)
                        &&
                        (this->parts.at(0)->get_y() > this->parts[i]->get_y() && this->parts.at(0)->get_y() < this->parts[i]->get_y() + this->parts[i]->get_length())
                        ) {
                    throw 2;
                }
            }
        }
    } else if (this->current_direction == 1) {
        for (int i = 2; i < this->parts.size(); i++) {
            if (this->parts[i]->get_dir() == 2 || this->parts[i]->get_dir() == -2) {
                if ((this->parts.at(0)->get_y() >= this->parts[i]->get_y() && this->parts.at(0)->get_y() < this->parts[i]->get_y() + this->size_of_body_part)
                        &&
                        (this->parts.at(0)->get_x() >= this->parts[i]->get_x() && this->parts.at(0)->get_x() < this->parts[i]->get_x() + this->parts[i]->get_length())
                        ) {
                    throw  2;
                }
            }
        }
    } else {
        for (int i = 2; i < this->parts.size(); i++) {
            if (this->parts[i]->get_dir() == 2 || this->parts[i]->get_dir() == -2) {
                if ((this->parts.at(0)->get_y() + this->parts.at(0)->get_length() > this->parts[i]->get_y() && this->parts.at(0)->get_y() + this->parts.at(0)->get_length() <= this->parts[i]->get_y() + this->size_of_body_part)
                        &&
                        (this->parts.at(0)->get_x() >= this->parts[i]->get_x() && this->parts.at(0)->get_x() <= this->parts[i]->get_x() + this->parts[i]->get_length())
                        ) {
                    throw 2;
                }
            }
        }
    }
}

bool Snake::is_eat_apple() {
    Body* part = this->parts.at(0);
    switch (this->parts.at(0)->get_dir()) {
        case 2: {
            if ((part->get_x() + part->get_length() > this->field->get_apple()->get_x() && part->get_x() + part->get_length() <= this->field->get_apple()->get_x() + this->field->get_apple()->get_size())
             && (part->get_y() > this->field->get_apple()->get_y() && part->get_y() + this->size_of_body_part < this->field->get_apple()->get_y() + this->field->get_apple()->get_size())) {
                return true;
            }
        }
        case -2: {
            if ((part->get_x() <= this->field->get_apple()->get_x() + this->field->get_apple()->get_size() && part->get_x() >= this->field->get_apple()->get_x())
            && part->get_y() > this->field->get_apple()->get_y() && part->get_y() + this->size_of_body_part < this->field->get_apple()->get_y() + this->field->get_apple()->get_size())
                return true;
        }
        case 1: {
            if ((part->get_y() >= this->field->get_apple()->get_y() && part->get_y() <= this->field->get_apple()->get_y() + this->field->get_apple()->get_size())
            && (part->get_x() > this->field->get_apple()->get_x() && part->get_x() + this->size_of_body_part < this->field->get_apple()->get_x() + this->field->get_apple()->get_size()))
                return true;
        }
        case -1: {
            if ((part->get_y() + part->get_length() >= this->field->get_apple()->get_y() && part->get_y() + part->get_length() <= this->field->get_apple()->get_y() + this->field->get_apple()->get_size())
            && (part->get_x() > this->field->get_apple()->get_x() && part->get_x() + this->size_of_body_part < this->field->get_apple()->get_x() + this->field->get_apple()->get_size()))
                return true;
        }
        default:
            return false;
    }
}