#include "GameOfLife.hpp"

#include "Configuration.hpp"

int main(int argc, char** argv) {

    for (size_t i = 0; i < argc; i++) {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;

    // todo: parse arguments

    auto configuration = std::make_shared<gol::Configuration>();

    // todo: Send parameters to Configuration

	gol::GameOfLife game(configuration);
	game.run();

	return 0;
}
