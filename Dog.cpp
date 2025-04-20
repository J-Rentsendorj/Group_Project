// Cpp file that includes the Dog header file and specifies what the new function and string in Dog.h do 
#include "Dog.h"
#include <iostream>

Dog::Dog(std::string name) : Pet(name) {}

void Dog::react() const {
    std::cout << name << " wags its tail happily (˶ˆᗜˆ˵)\n";
}

std::string Dog::toString() const {
    return "Dog," + name + "," + std::to_string(hunger) + "," + std::to_string(energy);
}
