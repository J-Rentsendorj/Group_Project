#include "Cat.h"
#include <iostream>

Cat::Cat(std::string name) : Pet(name) {}

void Cat::react() const {
    std::cout << name << " rubs up against you and meows happily\n";
}

std::string Cat::toString() const {
    return "Cat," + name + "," + std::to_string(hunger) + "," + std::to_string(energy);
}