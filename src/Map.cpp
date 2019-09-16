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

	size_t row = cell_index / line_length;
	size_t col = cell_index % line_length;
    size_t cells_number = get_cells_number();
    size_t number_of_lines = cells_number / line_length;

	// Booleans for checking edge positions
	bool left_edge = col == 0;
	bool right_edge = col == line_length - 1;
	bool top_edge = row == 0;
	bool bottom_edge = row == number_of_lines - 1;

	size_t upper_shift = 0;
	size_t right_shift = 0;
	size_t left_shift = 0;
	size_t lower_shift = 0;

    if (top_edge && type == TOROIDAL) upper_shift  = cells_number;
    if (right_edge && type == TOROIDAL) right_shift = -line_length;
    if (bottom_edge && type == TOROIDAL) lower_shift = -cells_number;
    if (left_edge && type == TOROIDAL) left_shift = line_length;

    if (!top_edge || type == TOROIDAL) result.push_back(cell_index - line_length + upper_shift); // UPPER
    if ((!top_edge && !right_edge) || type == TOROIDAL)
        result.push_back(cell_index - line_length + 1 + upper_shift + right_shift); // UPPER RIGHT
    if (!right_edge || type == TOROIDAL) result.push_back(cell_index + 1 + right_shift); // RIGHT
    if ((!bottom_edge && !right_edge) || type == TOROIDAL)
        result.push_back(cell_index + line_length + 1 + right_shift + lower_shift); // LOWER RIGHT
    if (!bottom_edge || type == TOROIDAL) result.push_back(cell_index + line_length + lower_shift); // LOWER
    if ((!bottom_edge && !left_edge) || type == TOROIDAL)
        result.push_back(cell_index + line_length - 1 + lower_shift + left_shift); // LOWER LEFT
    if (!left_edge || type == TOROIDAL) result.push_back(cell_index - 1 + left_shift); // LEFT
    if ((!top_edge && !left_edge) || type == TOROIDAL)
        result.push_back(cell_index - line_length - 1 + upper_shift + left_shift); // UPPER LEFT

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
