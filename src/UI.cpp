/*
 * UI.cpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#include "UI.hpp"

namespace gol {

UI::UI(Engine & r_engine, std::shared_ptr<Configuration> conf) : engine(r_engine), configuration(conf){

	window.create(
	        sf::VideoMode(configuration->get_window_width(),configuration->get_window_height()),
	        APP_NAME + " " + VERSION);
	window.setVerticalSyncEnabled(true);

	size_t line_cells_number = engine.get_map().get_line_length();
	size_t column_cells_number = engine.get_map().get_cells_number() / line_cells_number;
	rectangles_texture.create(line_cells_number * DEFAULT_CELL_SIZE, column_cells_number * DEFAULT_CELL_SIZE);

	rectangleNumber = engine.get_map().get_cells_number();
	rectangles = get_cells_rectangles(DEFAULT_CELL_SIZE);
}

void
UI::run() {

	sf::Clock clock;
	sf::Time timePerFrame = sf::milliseconds(16);

	while (window.isOpen()) {

		sf::Time start = clock.getElapsedTime();

		sf::Event event{};
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			} else if (event.type == sf::Event::MouseButtonPressed) {
                engine.toggle_cell(get_touched_cell_index(event.mouseButton.x, event.mouseButton.y));
			} else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::S) {
					engine.step();
				} else if (event.key.code == sf::Keyboard::R) {
					Map new_map = engine.get_map();
					new_map.reset_randomly_alive_percent(50);
					engine.set_map(new_map);
				} else if (event.key.code == sf::Keyboard::K) {
					Map new_map = engine.get_map();
					new_map.kill_all_cells();
					engine.set_map(new_map);
				}

                update_rectangles();
			}
		}

		window.clear();
        for (sf::RectangleShape& rectangle : rectangles) {
            window.draw(rectangle);
        }
		window.display();

		sf::Time end = clock.getElapsedTime();
		sf::Time sleeping = timePerFrame - end + start;
		if (sleeping.asMilliseconds() > 0) {
		    sf::sleep(sleeping);
		} else {
		    // It's lagging
		}
	}
}

std::vector<sf::RectangleShape>
UI::get_cells_rectangles(const float cells_width) const {
	std::vector<sf::RectangleShape> result;

	const std::vector<Cell> cells = engine.get_map().get_cells();
	const size_t cells_per_line_number = engine.get_map().get_line_length();

	for (size_t i = 0; i < cells.size(); ++i) {
		size_t x_shift = i % cells_per_line_number;
		size_t y_shift = i / cells_per_line_number;
		sf::RectangleShape rectangle(sf::Vector2f(cells_width, cells_width));

		if (cells[i].is_alive()) {
			rectangle.setFillColor(sf::Color::Blue);
		}

		rectangle.setPosition(sf::Vector2f(x_shift * DEFAULT_CELL_SIZE,y_shift * DEFAULT_CELL_SIZE));
		result.push_back(rectangle);
	}

	return result;
}

void
UI::update_rectangles() {

    const std::vector<Cell> cells = engine.get_map().get_cells();

    for (int i = 0; i < rectangleNumber; i++) {
        if (cells[i].is_alive()) {
            rectangles[i].setFillColor(sf::Color::Blue);
        } else {
            rectangles[i].setFillColor(sf::Color::White);
        }
    }
}

size_t
UI::get_touched_cell_index(const size_t x, const size_t y) const {
	const size_t width = engine.get_map().get_line_length();
	size_t column = x / (size_t) DEFAULT_CELL_SIZE;
	size_t line = y / (size_t) DEFAULT_CELL_SIZE;
	return column + line * width;
}

void
UI::update_rectangle_texture(sf::RenderTexture& texture) const {
    texture.clear(sf::Color::Red);
    for (auto const & rectangle : rectangles) {
        texture.draw(rectangle);
    }
    texture.display();
}

} /* namespace gol */
