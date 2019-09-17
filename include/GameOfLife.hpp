/*
 * GameOfLife.hpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#ifndef GAMEOFLIFE_HPP_
#define GAMEOFLIFE_HPP_

#include <utility>

#include "UI.hpp"
#include "Engine.hpp"
#include "constants.hpp"
#include "Configuration.hpp"

namespace gol {

/**
 * Defines the App, requires an Engine and a UI
 */
class GameOfLife {
public:
	explicit GameOfLife(std::shared_ptr<Configuration> conf):
		engine(std::unique_ptr<Engine>(new Engine(DEFAULT_RULE, DEFAULT_MAP))),
		ui(std::unique_ptr<UI>(new UI(*engine, conf))),
		configuration(conf)
	{}

	/** Starts the event manager, i.e. starts the App! */
	void run();

private:
	// todo: logger initialisation
	// todo: config loading

	std::unique_ptr<Engine> engine;
	std::unique_ptr<UI> ui;

	std::shared_ptr<Configuration> configuration;
};

} /* namespace gol */

#endif /* GAMEOFLIFE_HPP_ */
