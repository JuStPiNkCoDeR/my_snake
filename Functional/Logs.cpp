//
// Created by root on 15.04.19.
//

#include "../Headers/Logs.h"

Log::Log(sf::RenderWindow *window, const std::string& file_path, int font_size) {
    this->window = window;
    this->font.loadFromFile(file_path);
    this->fs = font_size;
    this->txt.setCharacterSize(this->fs);
    this->txt.setFont(this->font);
}

void Log::show(const std::string &text, sf::Color cl, float x, float y) {
    this->current_text += text;
    this->txt.setString(this->current_text);
    this->txt.setFillColor(cl);
    this->txt.setPosition(x, y);
}

void Log::append(const std::string &text) {
    this->current_text += text;
    this->txt.setString(this->current_text);
}

void Log::reset_text(const std::string &text) {
    this->current_text = text;
    this->txt.setString(this->current_text);
}

sf::Text Log::getText() {
    return this->txt;
}