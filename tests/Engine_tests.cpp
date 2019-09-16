#include <catch.hpp>

#include <Engine.hpp>

TEST_CASE("Engine class tests") {
	// UNIT TESTS
	// TODO


	// HIGH LEVEL TESTING
	SECTION("HIGH LEVEL TESTING") {
		SECTION("Standard rule B3S23") {
			SECTION("Small 'still lifes'") {
				SECTION("The Block") {
					gol::Engine engine(gol::Rule("B3S23"), gol::Map(4, 4));
					gol::Map new_map = engine.get_map();
					new_map.set_alive_cells(std::vector<size_t>({5, 6, 9, 10}));
					engine.set_map(new_map);
					engine.step();
					REQUIRE(engine.get_map().get_alive_cells_indexes() ==
							std::vector<size_t>({5, 6, 9, 10}));
				}
			}
			SECTION("Small oscillators") {
				SECTION("The Blinker") {
					gol::Engine engine(gol::Rule("B3S23"), gol::Map(5, 5));
					gol::Map new_map = engine.get_map();
					new_map.set_alive_cells(std::vector<size_t>({11, 12, 13}));
					engine.set_map(new_map);
					engine.step();
					REQUIRE(engine.get_map().get_alive_cells_indexes() ==
							std::vector<size_t>({7, 12, 17}));
					engine.step();
					REQUIRE(engine.get_map().get_alive_cells_indexes() ==
							std::vector<size_t>({11, 12, 13}));
				}
			}
		}
	}
}
