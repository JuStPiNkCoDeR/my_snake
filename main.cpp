#include <SFML/Graphics.hpp>
#include "Headers/relative_designer.h"
#include "Headers/game_field.h"
#include "Headers/wall.h"
#include "Headers/game_field.h"
#include "Headers/snake.h"
#include "Headers/Logs.h"

int main() {
    auto* relativeDesigner = new Relative_Designer(500, 500);
    auto* wall = new Wall(relativeDesigner->calculate_actual_y(3.f));
    Field* field;
    field = new Field(relativeDesigner->get_window_size_x(), relativeDesigner->get_window_size_y(),
                      wall->get_wall_dimension(), relativeDesigner);

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(relativeDesigner->get_window_size_x(), relativeDesigner->get_window_size_y()), "Is it GUI on C++?!");
    window->setVerticalSyncEnabled(true);

    auto* log = new Log(window, "/home/pinkcoder/Fonts/CuteFont-Regular.ttf", 26);
    //==========================================
    //| Borders here
    //==========================================
    sf::RectangleShape top_border(sf::Vector2f(relativeDesigner->calculate_actual_x(100.f), wall->get_wall_dimension()));
    top_border.setFillColor(sf::Color::White);
    top_border.setPosition(0.f, 0.f);
    sf::RectangleShape bottom_border = top_border;
    bottom_border.setPosition(0.f, relativeDesigner->calculate_actual_y(97.f));

    sf::RectangleShape left_border(sf::Vector2f(wall->get_wall_dimension(), relativeDesigner->calculate_actual_y(94.f)));
    left_border.setFillColor(sf::Color::White);
    left_border.setPosition(0.f, wall->get_wall_dimension());
    sf::RectangleShape right_border = left_border;
    right_border.setPosition(relativeDesigner->calculate_actual_x(97.f), wall->get_wall_dimension());

    auto* snake = new Snake(3.f, window, relativeDesigner, field, log);
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
        window->draw(top_border);
        window->draw(bottom_border);
        window->draw(left_border);
        window->draw(right_border);
        snake->draw();
        /// Тик для авто хода змейки
        if (c > 5) {
            snake->move();
            c = 0;
        }
        window->display();
        /// :3 <3
        c++;
    }
    return 0;
}