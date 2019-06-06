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

} /* namespace gol */
