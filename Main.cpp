#include <iostream>
#include <vector>
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"
#include "Bunny.h"
#include "Magikarp.h"
#include "FileHandler.h"
#include "PetException.h"

int main() {
    std::vector<Pet*> pets;
    loadFromFile(pets, "petsave.txt");

    int choice;
    std::string name;

    while (true) {
        std::cout << "\n1. Adopt Pet\n2. Interact with Pets\n3. Save & Exit\n> ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Choose a pet: 1. Dog  2. Cat  3. Pig  4. Bunny  5. Magikarp  \n> ";
            int type;
            std::cin >> type;
            std::cout << "Enter a name for your pet: ";
            std::cin >> name;

            if (type == 1) pets.push_back(new Dog(name));
            else if (type == 2) pets.push_back(new Cat(name));
            else if (type == 3) pets.push_back(new Pig(name));
            else if (type == 4) pets.push_back(new Bunny(name));
            else if (type == 5) pets.push_back(new Magikarp(name));
        }
        else if (choice == 2) {
            if (pets.empty()) {
                std::cout << "You don't have any pets yet;-;\n";
                continue;
            }

            for (size_t i = 0; i < pets.size(); ++i) {
                std::cout << i + 1 << ". " << pets[i]->getName()
                          << " (Hunger: " << pets[i]->getHunger()
                          << ", Energy: " << pets[i]->getEnergy() << ")\n";
            }

            std::cout << "Pick a pet number to interact with: ";
            size_t index;
            std::cin >> index;

            if (index < 1 || index > pets.size()) {
                std::cout << "Invalid selection.\n";
                continue;
            }

            Pet* selected = pets[index - 1];
            std::cout << "1. Feed  2. Play  3. Rest\n> ";
            int action;
            std::cin >> action;

            try {
                if (action == 1) selected->feed();
                else if (action == 2) {
                    if (selected->getEnergy() < 10)
                        throw PetException("Pet is too tired to play;-;");
                    selected->play();
                }
                else if (action == 3) selected->rest();
                else std::cout << "Invalid action.\n";

                selected->react();
            } catch (PetException& e) {
                std::cout << "Exception: " << e.what() << "\n";
            }
        }
        else if (choice == 3) {
            saveToFile(pets, "petsave.txt");
            std::cout << "Game saved. Goodbye!\n";
            break;
        }
    }

    for (auto p : pets) delete p;
    return 0;
}
