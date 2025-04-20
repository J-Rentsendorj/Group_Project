#include <iostream>
#include <vector>
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"
#include "Bunny.h"
#include "FileHandler.h"
#include "PetException.h"
// All necessary header files are above

// Main function where the code is put into action 
int main() {
    // Vector where all created pets are stored and a file that displays said pets and their information 
    std::vector<Pet*> pets;
    loadFromFile(pets, "petsave.txt");

    // Variables that take in user input and advance the following code 
    int choice;
    std::string name;

    // While loop to help the code run smoother and keeps going until stopped by the user 
    while (true) {
        // Asks the user what they want to do and stores their answer into int choice 
        std::cout << "\n1. Adopt Pet\n2. Interact with Pets\n3. Save & Exit\n> ";
        std::cin >> choice;

        // If statement that executes if choice is 1 which then asks what type of pet the user wants and what their name is
        if (choice == 1) {
            std::cout << "Choose a pet: 1. Dog  2. Cat  3. Pig  4. Bunny \n> ";
            int type;
            std::cin >> type;
            std::cout << "Enter a name for your pet: ";
            std::cin >> name;

           // If and else if statements that adds a new pet with the name that the user gave them to the vector 
            if (type == 1) pets.push_back(new Dog(name));
            else if (type == 2) pets.push_back(new Cat(name));
            else if (type == 3) pets.push_back(new Pig(name));
            else if (type == 4) pets.push_back(new Bunny(name));
        }
        // Else if statement that executes if choice is 2
        else if (choice == 2) {
            // If statement that executes if the vector called pets is empty and continues the program
            if (pets.empty()) {
                std::cout << "You don't have any pets yet;-;\n";
                continue;
            }
            // For loop that adds new pets to the vector and displays their information 
            for (size_t i = 0; i < pets.size(); ++i) {
                std::cout << i + 1 << ". " << pets[i]->getName()
                          << " (Hunger: " << pets[i]->getHunger()
                          << ", Energy: " << pets[i]->getEnergy() << ")\n";
            }

            // Asks the user which pet they want to play with by choosing the number given to them
            std::cout << "Pick a pet number to interact with: ";
            size_t index;
            std::cin >> index;

            // If statement that says invaild selection if index is less than 1 or index is greater than the number of pets in pets 
            if (index < 1 || index > pets.size()) {
                std::cout << "Invalid selection.\n";
                continue;
            }
            // Asks the user what they want to do with their pet and stores that input into action 
            Pet* selected = pets[index - 1];
            std::cout << "1. Feed  2. Play  3. Rest\n> ";
            int action;
            std::cin >> action;

            // Try block that executes different outcomes based on user input 
            try {
                if (action == 1) selected->feed();
                else if (action == 2) {
                    if (selected->getEnergy() < 10)
                        // Exception that throws pet is too tired to play if energy is less than 10
                        throw PetException("Pet is too tired to play;-;");
                    selected->play();
                }
                else if (action == 3) selected->rest();
                else std::cout << "Invalid action.\n";

                selected->react();
            // catch block that displays what is written in PetException 
            } catch (PetException& e) {
                std::cout << "Exception: " << e.what() << "\n";
            }
        }
        // Else if statement that saves all pets into the petsave text file and exits the code 
        else if (choice == 3) {
            saveToFile(pets, "petsave.txt");
            std::cout << "Game saved. Goodbye!\n";
            break;
        }
    }

    for (auto p : pets) delete p;
    return 0;
}
