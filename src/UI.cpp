/*
 * UI.cpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#include "UI.hpp"

namespace gol {

UI::UI(Engine & r_engine) : engine(r_engine){
	window.create(
		sf::VideoMode(
			DEFAULT_WINDOW_WIDTH_PX,
			DEFAULT_WINDOW_HEIGHT_PX),
		APP_NAME + " " + VERSION
	);
	window.setVerticalSyncEnabled(true);
	view = window.getDefaultView();
}

void
UI::run() {

	sf::Clock clock;
	sf::Time timePerFrame = sf::milliseconds(16);

	while (window.isOpen()) {

		sf::Time start = clock.getElapsedTime();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			} else if (event.type == sf::Event::MouseButtonPressed) {
				size_t x = event.mouseButton.x;
				size_t y = event.mouseButton.y;
				size_t index = get_touched_cell_index(x, y);
				const std::vector<size_t> indexes({index});
				Map new_map = engine.get_map();
				new_map.set_alive_cells(indexes);
				engine.set_map(new_map);
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
			}
		}

		window.clear();
		std::vector<sf::RectangleShape> rectangles =
				get_cells_rectangles(DEFAULT_RECTANGLE_SIZE);
		for (auto rectangle : rectangles) {
			window.draw(rectangle);
		}
		window.display();

		sf::Time end = clock.getElapsedTime();
		sf::sleep(timePerFrame - end + start);
	}
}

std::vector<sf::RectangleShape>
UI::get_cells_rectangles(const float cells_width) const {
	std::vector<sf::RectangleShape> result;

	const std::vector<Cell> cells = engine.get_map().get_cells();
	const size_t cells_per_line_number = engine.get_map().get_line_length();
	const size_t cells_per_column_number = cells.size() / cells_per_line_number;

	for (size_t i = 0; i < cells.size(); ++i) {
		size_t x_shift = i % cells_per_line_number;
		size_t y_shift = i / cells_per_line_number;
		sf::RectangleShape rectangle(
				sf::Vector2f(cells_width, cells_width));

		if (cells[i].is_alive()) {
			rectangle.setFillColor(sf::Color::Blue);
		}

		rectangle.setPosition(
			sf::Vector2f(
				x_shift * DEFAULT_CELL_SIZE,
				y_shift * DEFAULT_CELL_SIZE
			)
		);
		result.push_back(rectangle);
	}

	return result;
}

size_t
UI::get_touched_cell_index(const size_t x, const size_t y) const {
	const size_t width = engine.get_map().get_line_length();
	size_t column = x / (size_t) DEFAULT_CELL_SIZE;
	size_t line = y / (size_t) DEFAULT_CELL_SIZE;
	return column + line * width;
}


} /* namespace gol */
