#include <catch.hpp>

#include <Rule.hpp>

TEST_CASE("Rule Class") {
	SECTION("Rule constructor through 2 vectors") {
		std::vector<unsigned int> B, S;
		B.push_back(3);
		S.push_back(3);
		S.push_back(4);
		gol::Rule rule(B, S);
		REQUIRE(rule.get_rule_as_string() == "B3S34");
	}
	SECTION("Rule constructor through a string") {
		gol::Rule rule("B34S67");
		REQUIRE(rule.get_rule_as_string() == "B34S67");
	}
}
