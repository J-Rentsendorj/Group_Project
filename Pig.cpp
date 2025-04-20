// Cpp file that includes the Pig header file and specifies what the new function and string in Pig.h do
#include "Pig.h"
#include <iostream>

Pig::Pig(std::string name) : Pet(name) {}

void Pig::react() const {
    std::cout << name << " oinks with glee\n";
}

std::string Pig::toString() const {
    return "Pig," + name + "," + std::to_string(hunger) + "," + std::to_string(energy);
}
