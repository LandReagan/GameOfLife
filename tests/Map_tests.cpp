#include <catch.hpp>

#include <Map.hpp>

TEST_CASE("Map class tests") {

	SECTION("Constructor") {
		gol::Map map(50, 50);
		REQUIRE(map.get_line_length() == 50);
		REQUIRE(map.get_cells_number() == 2500);
	}

	SECTION("set_alive_cells  and set_dead_cells method") {
		gol::Map map(10, 10);
		auto cells = map.get_cells();
		REQUIRE(cells.at(10).is_alive() == false);
		REQUIRE(cells.at(20).is_alive() == false);
		REQUIRE(cells.at(30).is_alive() == false);

		map.set_alive_cells(std::vector<size_t>({10, 20, 30}));
		cells = map.get_cells();
		REQUIRE(cells.at(10).is_alive() == true);
		REQUIRE(cells.at(20).is_alive() == true);
		REQUIRE(cells.at(30).is_alive() == true);

		map.set_dead_cells(std::vector<size_t>({10, 20, 30}));
		cells = map.get_cells();
		REQUIRE(cells.at(10).is_alive() == false);
		REQUIRE(cells.at(20).is_alive() == false);
		REQUIRE(cells.at(30).is_alive() == false);
	}

	SECTION("Surrounding indexes calculation method, Standard type (non toroidal)") {
		gol::Map map(3, 3, gol::Map::STANDARD);
		// Indexes around central Cell in a 3x3 Map
		std::vector<size_t> indexes = map.get_surrounding_indexes(4);
		REQUIRE(indexes.size() == 8);
		std::sort(indexes.begin(), indexes.end());
		REQUIRE(indexes == std::vector<size_t>({0, 1, 2, 3, 5, 6, 7, 8}));

		indexes.clear();
		indexes = map.get_surrounding_indexes(0);
		std::sort(indexes.begin(), indexes.end());
		REQUIRE(indexes == std::vector<size_t>({1, 3, 4}));

		indexes.clear();
		indexes = map.get_surrounding_indexes(5);
		std::sort(indexes.begin(), indexes.end());
		REQUIRE(indexes == std::vector<size_t>({1, 2, 4, 7, 8}));
	}

    SECTION("Surrounding indexes calculation method, Toroidal type") {
        gol::Map map(3, 3, gol::Map::TOROIDAL);
        // Indexes around central Cell in a 3x3 Map
        std::vector<size_t> indexes = map.get_surrounding_indexes(4);
        REQUIRE(indexes.size() == 8);
        std::sort(indexes.begin(), indexes.end());
        REQUIRE(indexes == std::vector<size_t>({0, 1, 2, 3, 5, 6, 7, 8}));

        indexes.clear();
        indexes = map.get_surrounding_indexes(0);
        std::sort(indexes.begin(), indexes.end());
        REQUIRE(indexes == std::vector<size_t>({1, 2, 3, 4, 5, 6, 7, 8}));

        indexes.clear();
        indexes = map.get_surrounding_indexes(5);
        std::sort(indexes.begin(), indexes.end());
        REQUIRE(indexes == std::vector<size_t>({0, 1, 2, 3, 4, 6, 7, 8}));
    }
}
