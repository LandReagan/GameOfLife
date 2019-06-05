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
	for (size_t i = 0; i < cells.size(); i++) {
		Cell& cell = cells[i];
		if (cell.is_alive()) {
			// Check for survival
		} else {
			// Check for birth
		}
	}
}

} /* namespace gol */
