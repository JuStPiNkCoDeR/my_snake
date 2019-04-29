#include <SFML/Graphics.hpp>
#include "Headers/relative_designer.h"
#include "Headers/game_field.h"
#include "Headers/wall.h"
#include "Headers/game_field.h"
#include "Headers/snake.h"
#include "Headers/Logs.h"

int main() {
    auto* relativeDesigner = new Relative_Designer(500, 500);

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(relativeDesigner->get_window_size_x(), relativeDesigner->get_window_size_y()), "Is it GUI on C++?!");
    window->setVerticalSyncEnabled(true);

    auto* log = new Log(window, "/home/pinkcoder/Fonts/CuteFont-Regular.ttf", 26);
    log->show("", sf::Color::White, 20.f, 10.f);

    Field* field;
    field = new Field(relativeDesigner->get_window_size_x(), relativeDesigner->get_window_size_y(), window, relativeDesigner, log);

    auto* snake = new Snake(5, window, relativeDesigner, field, log);

    int c = 0;
    while (window->isOpen()) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                snake->go_down();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
                snake->go_up();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
                snake->go_left();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                snake->go_right();
            }
        }

        window->clear();
        snake->draw();
        field->draw();
        /// Тик для авто хода змейки
        if (c > 2) {
            snake->move();
            c = 0;
        }
        window->display();
        /// :3 <3
        c++;
    }
    return 0;
}