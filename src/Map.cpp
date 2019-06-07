/*
 * Map.cpp
 *
 *  Created on: 26 May 2019
 *      Author: landry
 */

#include "Map.hpp"

namespace gol {

Map::Map(std::size_t width, std::size_t height) {
	line_length = width;
	cells.assign(width * height, Cell());
}

void
Map::set_alive_cells(const std::vector<size_t> & indexes) {
	for (auto index : indexes) {
		if (index < cells.size()) {
			cells.at(index).make_alive();
		}
	}
}

void
Map::set_dead_cells(const std::vector<size_t> & indexes) {
	for (auto index : indexes) {
		if (index < cells.size()) {
			cells.at(index).kill();
		}
	}
}

void
Map::kill_all_cells() {
	for (Cell cell : cells) cell.kill();
}

void
Map::reset_randomly_alive_percent(const size_t percents) {
	kill_all_cells();
	std::srand(std::time(nullptr));
	while (get_alive_cells_indexes().size() < cells.size() * percents / 100) {
		size_t index = (size_t) cells.size() * std::rand() / RAND_MAX;
		set_alive_cells(std::vector<size_t>({index}));
	}
}

std::vector<size_t>
Map::get_surrounding_indexes(const size_t cell_index) const {

	std::vector<size_t> result;

	// Booleans for checking edge positions
	bool left_edge = false;
	bool right_edge = false;
	bool top_edge = false;
	bool bottom_edge = false;

	size_t number_of_lines = cells.size() / line_length;

	// Setting the booleans with so smart arithmetics
	if (cell_index / line_length == 0) top_edge = true;
	if (cell_index % line_length == 0) left_edge = true;
	if (cell_index % line_length == line_length - 1) right_edge = true;
	if (cell_index / line_length == number_of_lines - 1) bottom_edge = true;

	if (!top_edge) {
		result.push_back(cell_index - line_length); // top
	}
	if (!left_edge && !left_edge) {
		result.push_back(cell_index - line_length - 1); // top left
	}
	if (!left_edge) {
		result.push_back(cell_index - 1); // left
	}
	if (!right_edge && !top_edge) {
		result.push_back(cell_index - line_length + 1); // top right
	}
	if (!right_edge) {
		result.push_back(cell_index + 1); // right
	}
	if (!bottom_edge) {
		result.push_back(cell_index + line_length); // bottom
	}
	if (!bottom_edge && !left_edge) {
		result.push_back(cell_index + line_length - 1); // bottom left
	}
	if (!bottom_edge && !right_edge) {
		result.push_back(cell_index + line_length + 1); // bottom right
	}

	return result;
}

std::vector<size_t>
Map::get_alive_cells_indexes() const {

	std::vector<size_t> result;
	for (size_t i = 0; i < cells.size(); i++) {
		if (cells[i].is_alive()) result.push_back(i);
	}
	return result;
}

} /* namespace gol */
