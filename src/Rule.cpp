/*
 * Rule.cpp
 *
 *  Created on: 25 May 2019
 *      Author: landry
 */

#include "Rule.hpp"

namespace gol {

Rule::Rule(std::vector<unsigned int> cB, std::vector<unsigned int> cS) {
	set_B(cB);
	set_S(cS);
}

Rule::Rule(std::string rule_string) {
	set_rule(rule_string);
}

void
Rule::set_rule(std::string string_rule) {
	std::string pattern = "B(\\d+)S(\\d+)";
	std::regex rule_re(pattern);
	std::smatch match;
	if (std::regex_match(string_rule, match, rule_re)) {
		std::string born_match = match[1].str();
		for (size_t i = 0; i < born_match.size(); i++) {
			B.push_back(std::stoi(born_match.substr(i, 1)));
		}
		std::string survival_match = match[2].str();
		for (size_t i = 0; i < survival_match.size(); i++) {
			S.push_back(std::stoi(survival_match.substr(i, 1)));
		}
	} else { // will erase any rule previously set, for error management at higher level...
		B.clear();
		S.clear();
	}
}

std::string
Rule::get_rule_as_string() const {
	std::ostringstream result;
	result << "B";
	for (auto birth_value : B) {
		result << birth_value;
	}
	result << "S";
	for (auto survival_value : S) {
		result << survival_value;
	}
	return result.str();
}

} /* namespace gol */
