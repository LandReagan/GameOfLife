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

	SECTION("check_survival_rule and check_birth_rule methods") {
		gol::Rule rule("B34S67");
		REQUIRE(rule.check_birth_rule(3) == true);
		REQUIRE(rule.check_birth_rule(4) == true);
		REQUIRE(rule.check_birth_rule(5) == false);
		REQUIRE(rule.check_survival_rule(6) == true);
		REQUIRE(rule.check_survival_rule(7) == true);
		REQUIRE(rule.check_survival_rule(5) == false);
	}


}
