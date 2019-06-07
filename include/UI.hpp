/*
 * UI.hpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#ifndef UI_HPP_
#define UI_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine.hpp"
#include "constants.hpp"
#include "GolWindow.hpp"

namespace gol {

/**
 * This class depends upon SFML library. It requires an Engine to work.
 */
class UI {

public:
	/** Constructor only requires an Engine */
	UI(Engine & r_engine);

	/** Method to call to launch the SFML event manager */
	void run();

private:
	Engine & engine;

	std::vector<sf::RectangleShape>
	get_cells_rectangles(const float cells_width) const;

	size_t
	get_touched_cell_index(const size_t x, const size_t y) const;

	// SFML stuff
	GolWindow window;
	sf::View view;
};

} /* namespace gol */

#endif /* UI_HPP_ */
