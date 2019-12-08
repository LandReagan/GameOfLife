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
#include "Configuration.hpp"
#include "constants.hpp"
#include "GolWindow.hpp"

namespace gol {

/**
 * This class depends upon SFML library. It requires an Engine to work.
 */
class UI {

public:
	/** Constructor only requires an Engine */
	explicit UI(Engine&, std::shared_ptr<Configuration>);

	/** Method to call to launch the SFML event manager */
	void run();

private:
	Engine & engine;
	sf::RenderTexture rectangles_texture;
    std::vector<sf::RectangleShape> rectangles;
    int rectangleNumber;

    std::vector<sf::RectangleShape>
    get_cells_rectangles(float cells_width) const;

    void
    update_rectangles();

	size_t
	get_touched_cell_index(size_t x, size_t y) const;

	void
	update_rectangle_texture(sf::RenderTexture&) const;

	// SFML stuff
	GolWindow window;

	// Configuration
	std::shared_ptr<Configuration> configuration;

};

} /* namespace gol */

#endif /* UI_HPP_ */
