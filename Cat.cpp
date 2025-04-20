// Cpp file that includes the Cat header file and specifies what the new function and string in Cat.h do 
#include "Cat.h"
#include <iostream>

Cat::Cat(std::string name) : Pet(name) {}

void Cat::react() const {
    std::cout << name << " rubs up against you and meows happily\n";
}

std::string Cat::toString() const {
    return "Cat," + name + "," + std::to_string(hunger) + "," + std::to_string(energy);
}
