//
// Created by landry on 01/09/2019.
//

#ifndef GAMEOFLIFE_UTILS_DEBUG_HPP
#define GAMEOFLIFE_UTILS_DEBUG_HPP

#include <string>
#include <iostream>
#include "GolWindow.hpp"

namespace gol {

std::string
describe_window(const GolWindow& window) {
    std::cout << "GolWindow at x:" << window.getPosition().x << " y:" << window.getPosition().y << std::endl;
}

} // namespace gol

#endif //GAMEOFLIFE_UTILS_DEBUG_HPP
