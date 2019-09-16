/*
 * Engine.cpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#include "Engine.hpp"

namespace gol {

void
Engine::step() {

	auto cells = map.get_cells();
	std::vector<size_t> cells_to_set_alive;
	std::vector<size_t> cells_to_set_dead;

	for (size_t i = 0; i < cells.size(); i++) {

		const Cell& cell = cells[i];
		const std::vector<size_t> surrounding_cells_indexes =
				map.get_surrounding_indexes(i);

		size_t alive_surrounding_cells_number = 0;
		for (size_t i : surrounding_cells_indexes) {
			if (cells[i].is_alive()) alive_surrounding_cells_number++;
		}

		if (cell.is_alive()) {
			// Check for survival
			if (rule.check_survival_rule(alive_surrounding_cells_number)) {
				cells_to_set_alive.push_back(i);
			} else {
				cells_to_set_dead.push_back(i);
			}
		} else {
			// Check for birth
			if (rule.check_birth_rule(alive_surrounding_cells_number)) {
				cells_to_set_alive.push_back(i);
			} else {
				cells_to_set_dead.push_back(i);
			}
		}
	}
	map.set_alive_cells(cells_to_set_alive);
	map.set_dead_cells(cells_to_set_dead);
}

void
Engine::toggle_cell(const size_t index) {
    map.toggle_cell_at(index);
}

} /* namespace gol */
