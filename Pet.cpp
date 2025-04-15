#include "Pet.h"
#include <iostream>

Pet::Pet(std::string name) : name(name), hunger(100), energy(100) {}

void Pet::feed() {
    hunger -= 10;
    if (hunger < 0) hunger = 0;
    std::cout << name << " has been fed.\n";
}

void Pet::play() {
    hunger += 10;
    energy -= 15;
    std::cout << name << " played happily with you.\n";
}

void Pet::rest() {
    energy += 20;
    if (energy > 100) energy = 100;
    std::cout << name << " is resting.\n";
}

std::string Pet::getName() const {
    return name;
}

int Pet::getHunger() const {
    return hunger;
}

int Pet::getEnergy() const {
    return energy;
}
