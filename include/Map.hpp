/*
 * Map.hpp
 *
 *  Created on: 26 May 2019
 *      Author: landry
 */

#ifndef MAP_HPP_
#define MAP_HPP_

#include <Cell.hpp>

#include  <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

namespace gol {

/**
 * \brief Defines the Map, dimensions and Cells state.
 *
 * The Map is defined by a vector of Cell and a line length
 */
class Map {

public:

    /** Boundary types define how the surrounding indexes are calculated*/
    enum BoundaryType {STANDARD, TOROIDAL};

	/** Ctor takes a width and a height, and optionally a boundary */
	Map(std::size_t width, std::size_t height);
	Map(std::size_t width, std::size_t height, BoundaryType);

	/** line_length getter */
	std::size_t get_line_length() const { return line_length; }
	/** Cells number getter */
	std::size_t get_cells_number() const { return cells.size(); }
	/** Vector of Cell getter */
	const std::vector<Cell>& get_cells() const { return cells; }

	/** Setter for alive cells at index, whatever previous state */
	void set_alive_cells(const std::vector<size_t> & indexes);
	/** Setter for dead cells at index, whatever previous state */
	void set_dead_cells(const std::vector<size_t> & indexes);

	/** Toggle Cell's state at index */
	void toggle_cell_at(const size_t);

	/** Self explanatory... */
	void kill_all_cells();
	/** Reset the Map to a new state where parameter is percentage of alive
	 * cells, distributed randomly */
	void reset_randomly_alive_percent(const size_t percents);

	/** Getter for a Cell's surrounding indexes */
	std::vector<size_t> get_surrounding_indexes(const size_t cell_index) const;
	/** Getter for alive cells indexes */
	std::vector<size_t> get_alive_cells_indexes() const;

private:
	std::size_t line_length;
	std::vector<Cell> cells;
	BoundaryType type;
};

} /* namespace gol */

#endif /* MAP_HPP_ */
