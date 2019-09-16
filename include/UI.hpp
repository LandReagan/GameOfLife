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
#include <thread>
#include <chrono>

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
	explicit UI(Engine & r_engine);

	/** Method to call to launch the SFML event manager */
	void run();

private:
	Engine & engine;
	sf::RenderTexture rectangles_texture;

    std::vector<sf::RectangleShape>
    get_cells_rectangles(float cells_width) const;

	size_t
	get_touched_cell_index(size_t x, size_t y) const;

	void
	update_rectangle_texture(sf::RenderTexture&, const std::vector<sf::RectangleShape> &) const;

	// SFML stuff
	GolWindow window;

};

} /* namespace gol */

#endif /* UI_HPP_ */
