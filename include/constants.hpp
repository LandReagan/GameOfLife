/*
 * constants.hpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

#include <string>
#include <vector>

#include "Rule.hpp"
#include "Map.hpp"

const std::string APP_NAME = "Game Of Life";
const std::string VERSION = "v0.0.1";

/*
 * Graphics constants:
 */
const size_t DEFAULT_WINDOW_HEIGHT_PX = 1000;
const size_t DEFAULT_WINDOW_WIDTH_PX = 1000;
const float DEFAULT_CELL_SIZE = 10.0;
const float DEFAULT_RECTANGLE_SIZE = 10.0;

// Rules
const gol::Rule DEFAULT_RULE("B3S23");

// Map
const gol::Map DEFAULT_MAP(100, 100);

#endif /* CONSTANTS_HPP_ */
