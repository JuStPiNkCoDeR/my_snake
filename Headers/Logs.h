//
// Created by root on 15.04.19.
//

#include <SFML/Graphics.hpp>
#ifndef CONSOLE_SNAKE_LOGS_H
#define CONSOLE_SNAKE_LOGS_H
class Log {
private:
    sf::RenderWindow* window;
    sf::Font font;
    int fs;
    std::string current_text = "";
    sf::Text txt;
public:
    Log(sf::RenderWindow* window, const std::string& file_path, int font_size);
    void show(const std::string& text, sf::Color cl, float x, float y);
    void append(const std::string& text);
    void reset_text(const std::string& text);
    sf::Text getText();
};
#endif //CONSOLE_SNAKE_LOGS_H
