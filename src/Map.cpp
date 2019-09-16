/*
 * Map.cpp
 *
 *  Created on: 26 May 2019
 *      Author: landry
 */

#include "Map.hpp"

namespace gol {

Map::Map(std::size_t width, std::size_t height) : Map(width, height, BoundaryType::TOROIDAL){}

Map::Map(std::size_t width, std::size_t height, Map::BoundaryType type) : line_length(width), type(type) {
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
Map::toggle_cell_at(const size_t index) {
    cells[index].toggle();
}

void
Map::kill_all_cells() {
	for (Cell & cell : cells) cell.kill();
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
	size_t cells_number = get_cells_number();

	// Setting the booleans with so smart arithmetic
	if (cell_index / line_length == 0) top_edge = true;
	if (cell_index % line_length == 0) left_edge = true;
	if (cell_index % line_length == line_length - 1) right_edge = true;
	if (cell_index / line_length == number_of_lines - 1) bottom_edge = true;

    if (!top_edge) { // top
        result.push_back(cell_index - line_length);
    } else if (type == TOROIDAL) {
        result.push_back(cell_index - line_length + cells_number);
    }
    if (!top_edge && !left_edge) { // top left
        result.push_back(cell_index - line_length - 1);
    } else if (type == TOROIDAL) {
        result.push_back(cell_index - line_length - 1 + cells_number + line_length);
    }
    if (!left_edge) { // left
        result.push_back(cell_index - 1);
    } else if (type == TOROIDAL) {
        result.push_back(cell_index - 1 + line_length);
    }
    if (!right_edge && !top_edge) { // top right
        result.push_back(cell_index - line_length + 1);
    } else if (type == TOROIDAL) {
        result.push_back(cell_index - line_length + 1 + cells_number - line_length);
    }
    if (!right_edge) { // right
        result.push_back(cell_index + 1);
    } else if (type == TOROIDAL) {
        result.push_back(cell_index + 1 - line_length);
    }
    if (!bottom_edge) { // bottom
        result.push_back(cell_index + line_length);
    } else if (type == TOROIDAL) {
        result.push_back(cell_index + line_length - cells_number);
    }
    if (!bottom_edge && !left_edge) { // bottom left
        result.push_back(cell_index + line_length - 1);
    } else if (type == TOROIDAL) {
        result.push_back(cell_index + line_length - 1 - cells_number + line_length);
    }
    if (!bottom_edge && !right_edge) {
        result.push_back(cell_index + line_length + 1); // bottom right
    } else if (type == TOROIDAL) {
        result.push_back(cell_index + line_length + 1 - cells_number - line_length); // bottom right
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
