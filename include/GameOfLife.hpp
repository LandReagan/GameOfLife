/*
 * GameOfLife.hpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#ifndef GAMEOFLIFE_HPP_
#define GAMEOFLIFE_HPP_

#include "UI.hpp"
#include "Engine.hpp"
#include "constants.hpp"

namespace gol {

class GameOfLife {
public:
	GameOfLife(): engine(Engine(DEFAULT_RULE, DEFAULT_MAP)), ui(engine) {}

	void run();

private:
	// todo: logger initialisation
	// todo: config loading

	Engine engine;
	UI ui;
};

} /* namespace gol */

#endif /* GAMEOFLIFE_HPP_ */
