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

namespace gol {

/**
 * \brief Defines the Map, dimensions and Cells state.
 *
 * The Map is defined by a vector of Cell and a line length
 */
class Map {

public:
	/** Only constructor, takes a width and a height */
	Map(std::size_t width, std::size_t height);

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

	/** Getter for a Cell's surrounding indexes */
	std::vector<size_t> get_surrounding_indexes(const size_t cell_index) const;

private:
	std::size_t line_length;
	std::vector<Cell> cells;
};

} /* namespace gol */

#endif /* MAP_HPP_ */
