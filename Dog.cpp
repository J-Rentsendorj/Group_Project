#include "Dog.h"
#include <iostream>

Dog::Dog(std::string name) : Pet(name) {}

void Dog::react() const {
    std::cout << name << " wags its tail happily (˶ˆᗜˆ˵)\n";
}

std::string Dog::toString() const {
    return "Dog," + name + "," + std::to_string(hunger) + "," + std::to_string(energy);
}
