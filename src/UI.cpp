/*
 * UI.cpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#include "UI.hpp"

namespace gol {

void UI::run() {
	sf::RenderWindow window(
			sf::VideoMode(DEFAULT_WINDOW_WIDTH_PX, DEFAULT_WINDOW_HEIGHT_PX),
			APP_NAME + VERSION);

	std::vector<sf::RectangleShape> rectangles = get_cells_rectangles();

	while (window.isOpen()) {
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
			}
		}

		window.clear();
		rectangles = get_cells_rectangles();
		for (auto rectangle : rectangles) {
			window.draw(rectangle);
		}
		window.display();
	}
}

std::vector<sf::RectangleShape>
UI::get_cells_rectangles() const {
	std::vector<sf::RectangleShape> result;

	const size_t width = engine.get_map().get_line_length();
	const std::vector<Cell> cells = engine.get_map().get_cells();

	for (size_t i = 0; i < cells.size(); ++i) {
		size_t x_shift = i % width;
		size_t y_shift = i / width;
		sf::RectangleShape rectangle(sf::Vector2f(DEFAULT_RECTANGLE_SIZE, DEFAULT_RECTANGLE_SIZE));

		if (cells[i].is_alive()) {
			rectangle.setFillColor(sf::Color::Blue);
		}

		rectangle.setPosition(sf::Vector2f(x_shift * DEFAULT_CELL_SIZE, y_shift * DEFAULT_CELL_SIZE));
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
