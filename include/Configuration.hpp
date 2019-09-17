//
// Created by landry on 16/09/2019.
//

#ifndef GAMEOFLIFE_CONFIGURATION_HPP
#define GAMEOFLIFE_CONFIGURATION_HPP

#include <cstddef>

#include "constants.hpp"

namespace gol {

class Configuration {

public:
    Configuration();

    size_t get_window_height() { return window_height; }
    size_t get_window_width() { return window_width; }

private:
    size_t window_height;
    size_t window_width;
};

} // namespace gol

#endif //GAMEOFLIFE_CONFIGURATION_HPP
