/*
 * Window.cpp
 *
 *  Created on: 7 Jun 2019
 *      Author: landry
 */

#include "../include/GolWindow.hpp"

namespace gol {

void
GolWindow::draw_all() {
	clear();
	for (sf::RectangleShape square : squares) {
		draw(square);
	}
	display();
}

} /* namespace gol */
