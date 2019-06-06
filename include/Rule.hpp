/**
 * \file Rule.hpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#ifndef RULE_HPP_
#define RULE_HPP_

#include <string>
#include <regex>
#include <vector>

#include <iostream>

namespace gol {

/**
 * \class Rule
 * \brief Defines the Game of life rule to be applied
 *
 * This rule is usually defined with a string like B3S23 (this is the standard
 * rule, btw) which means: BORN if surrounded by 3, SURVIVING if surrounded by
 * 2 or 3.
 */
class Rule {

public:
	/** Rule ctor from 2 vectors. */
	Rule(std::vector<unsigned int> cB, std::vector<unsigned int> cS);
	/**
	 *  Rule ctor from a string, with format: "B3S23" (example: standard rule).
	 *  Number of digits for birth or survival has to be one or more.
	 */
	Rule(std::string rule_string);

	/** B setter */
	inline void set_B(const std::vector<unsigned int> & new_B)
		{ B.assign(new_B.begin(), new_B.end()); }
	/** S setter */
	inline void set_S(const std::vector<unsigned int> & new_S)
		{ S.assign(new_S.begin(), new_S.end()); }
	/** Rule setter from a string */
	void set_rule(std::string rule_string);

	/** Rule getter as a string */
	std::string get_rule_as_string() const;

	/** Checks if number n is in the B rule */
	inline bool check_birth_rule(size_t n) {
		return std::find(B.begin(), B.end(), n) != B.end();
	}

	/** Checks if number n is in the S rule */
	inline bool check_survival_rule(size_t n) {
		return std::find(S.begin(), S.end(), n) != S.end();
	}

private:
	std::vector<unsigned int> B;
	std::vector<unsigned int> S;
};

} /* namespace gol */

#endif /* RULE_HPP_ */
