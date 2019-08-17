/*
 * Window.hpp
 *
 *  Created on: 7 Jun 2019
 *      Author: landry
 */

#ifndef INCLUDE_GOLWINDOW_HPP_
#define INCLUDE_GOLWINDOW_HPP_

#include <SFML/Graphics.hpp>

namespace gol {
/**
 * Interface class between SFML and the App
 */
class GolWindow : public sf::RenderWindow {

public:
	/** Call this method to clear the window, draw the stuff, and display */
	void draw_all();

protected:
	/** Just to avoid resizing of the sprites inside the window... */
	virtual void onResize() {}

private:
	std::vector<sf::RectangleShape> squares;

};

} /* namespace gol */

#endif /* INCLUDE_GOLWINDOW_HPP_ */
