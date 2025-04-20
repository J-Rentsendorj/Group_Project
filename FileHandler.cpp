// Header file that includes the FileHandler and Dog header files and specifies what the functions in FileHandler.h do
#include "FileHandler.h"
#include "Dog.h"
#include <fstream>
#include <sstream>

void saveToFile(const std::vector<Pet*>& pets, const std::string& filename) {
    std::ofstream file(filename);
    for (auto p : pets) {
        file << p->toString() << "\n";
    }
    file.close();
}

void loadFromFile(std::vector<Pet*>& pets, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string type, name;
        int hunger, energy;

        getline(ss, type, ',');
        getline(ss, name, ',');
        ss >> hunger;
        ss.ignore();
        ss >> energy;

        Pet* pet = nullptr;
        if (type == "Dog") pet = new Dog(name);

        if (pet) {
            pet->feed();
            pets.push_back(pet);
        }
    }

    file.close();
}
