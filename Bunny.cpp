#include "Bunny.h"
#include <iostream>

Bunny::Bunny(std::string name) : Pet(name) {}

void Bunny::react() const {
    std::cout << name << " Hops around happily!\n";
}

std::string Bunny::toString() const {
    return "Bunny," + name + "," + std::to_string(hunger) + "," + std::to_string(energy);
}
