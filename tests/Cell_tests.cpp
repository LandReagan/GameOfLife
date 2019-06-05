#include <catch.hpp>

#include <Cell.hpp>

TEST_CASE("Cell class tests") {

	SECTION("Constructors") {
		SECTION("Default constructor") {
			gol::Cell cell;
			REQUIRE(cell.is_alive() == false);
		}
	}

	SECTION("Cell methods 'make_alive()' and 'kill()'") {
		gol::Cell cell;
		cell.make_alive();
		REQUIRE(cell.is_alive() == true);
		cell.kill();
		REQUIRE(cell.is_alive() == false);
	}
}
