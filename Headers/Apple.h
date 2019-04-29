//
// Created by root on 22.04.19.
//
#include <SFML/Graphics.hpp>

#ifndef CONSOLE_SNAKE_APPLE_H
#define CONSOLE_SNAKE_APPLE_H
class Apple {
private:
    sf::RenderWindow* window;
    sf::Texture* texture;
    sf::RectangleShape* shape;
    float x, y, size;
    bool bad;
public:
    Apple(sf::RenderWindow *w, const std::string& file_path, float x, float y, float width, bool bad = false);
    sf::RectangleShape get_shape();
    float get_x();
    float get_y();
    float get_size();
};
#endif //CONSOLE_SNAKE_APPLE_H
