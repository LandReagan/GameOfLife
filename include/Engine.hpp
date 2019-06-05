/*
 * Engine.hpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "Rule.hpp"
#include "Map.hpp"

namespace gol {

/**
 * \brief This class contains the data and the calculations logic, if provided with
 * the rule
 */
class Engine {
public:
	/** To construct an Engine, a Rule and a Map are required! */
	Engine(Rule c_rule, Map c_map) : rule(c_rule), map(c_map) {}

	/** Map getter */
	Map get_map() const { return map; }

	/** Map setter */
	void set_map(const Map new_map) { map = new_map; }

	/**\brief Method to call for calculation of one step ahead.
	 * The Map provides a reader for the Cells collection but gets a collection
	 * of indexes to set the alive Cells. This method reads the Cells and then
	 * populates the indexes!
	 */
	void step();

private:
	Rule rule;
	Map map;
};

} /* namespace gol */

#endif /* ENGINE_HPP_ */
