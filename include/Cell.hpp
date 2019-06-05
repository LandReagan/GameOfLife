/*
 * Cell.cpp
 *
 *  Created on: 05 June 2019
 *      Author: landry
 */

#ifndef CELL_HPP_
#define CELL_HPP_

namespace gol {

/**
 * This class represents a cell on the Map. It is dead on construction. To give
 * birth, use method [make_alive], to make it dead use [kill].
 */
class Cell {
public:
	/** default constructor */
	inline Cell() : alive(false) {}

	/** Getter for alive */
	inline bool is_alive() const { return alive; }

	/** Make the Cell alive whatever its previous state */
	inline void make_alive() { alive = true; }
	/** Make the Cell NOT alive whatever its previous state */
	inline void kill() { alive = false; }

private:
	bool alive;
};

} /* namespace gol */

#endif
