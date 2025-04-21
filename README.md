# Group Project: Pet Management Game

Welcome to the **Pet Management Game**, a console-based C++ application where you can adopt, interact with, and care for virtual pets. This project demonstrates object-oriented programming concepts, file handling, and exception management in C++.

## Table of Contents
1. [Features](#features)
2. [Technologies Used](#technologies-used)
3. [Project Structure](#project-structure)
4. [Setup and Installation](#setup-and-installation)
5. [How to Play](#how-to-play)
6. [File Format](#file-format)
7. [Code Overview](#code-overview)
8. [Future Enhancements](#future-enhancements)
9. [License](#license)

## Features
- **Adopt Pets**: Choose from four pet types (Dog, Cat, Pig, Bunny) and give them unique names.
- **Interact with Pets**:
  - Feed your pets to reduce hunger.
  - Play with your pets to increase happiness (requires sufficient energy).
  - Let your pets rest to restore energy.
- **Save and Load Progress**:
  - Save your pets' data to a file (`petsave.txt`) and load it in future sessions.
- **Exception Handling**: Handles invalid actions (e.g., playing with a tired pet) using custom exceptions.
- **Dynamic Memory Management**: Pets are dynamically allocated and properly cleaned up to avoid memory leaks.

## Technologies Used
- **C++17**: Modern C++ standard with smart pointers, exception handling, and STL.
- **Standard Libraries**:
  - `<iostream>`: Input/output operations.
  - `<vector>`: Managing dynamic pet lists.
  - `<fstream>`: File input/output.
  - `<sstream>`: String parsing.
- **Custom Classes**:
  - `Pet` (base class) and derived classes (`Dog`, `Cat`, `Pig`, `Bunny`).
  - `FileHandler` for saving/loading pet data.
  - `PetException` for pet-related error handling.

## Project Structure
```
Group_Project-main/
├── Main.cpp                  # Main entry point of the program
├── Dog.cpp / Dog.h           # Implementation of the Dog class
├── Cat.cpp / Cat.h           # Implementation of the Cat class
├── Pig.cpp / Pig.h           # Implementation of the Pig class
├── Bunny.cpp / Bunny.h       # Implementation of the Bunny class
├── Pet.cpp / Pet.h           # Base class for all pets
├── FileHandler.cpp / .h      # Handles saving/loading pet data
├── PetException.h            # Custom exception class
├── petsave.txt               # Save file for pet data
```

## Setup and Installation

### Prerequisites
- A C++ compiler (e.g., GCC, MinGW, or MSVC)
- A terminal or command prompt

### Steps to Compile and Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-repo/pet-management-game.git
   cd pet-management-game
   ```

2. **Compile the Code**:

   Using GCC:
   ```bash
   g++ -o main Main.cpp Dog.cpp Cat.cpp Pig.cpp Bunny.cpp Pet.cpp FileHandler.cpp -std=c++17
   ```

   Using MSVC (Visual Studio):
   - Create a new project.
   - Add all `.cpp` and `.h` files.
   - Build the project.

3. **Run the Program**:
   ```bash
   ./main
   ```

4. **Create a Save File** (if it doesn't exist):
   ```bash
   touch petsave.txt
   ```

## How to Play

- **Adopt a Pet**: Choose a type (Dog, Cat, Pig, Bunny) and name it.
- **View Stats**: Check your pets' hunger and energy levels.
- **Interact**:
  - **Feed**: Reduces hunger.
  - **Play**: Increases happiness, costs energy.
  - **Rest**: Restores energy.
- **Save & Exit**: Your pets' data will be stored in `petsave.txt`.

## File Format

The save file `petsave.txt` uses this format:
```
type,name,hunger,energy
```

Example:
```
Dog,Max,50,80
Cat,Luna,40,90
Pig,Babe,60,70
Bunny,Fluffy,30,100
```

## Code Overview

### Main Program (`Main.cpp`)
- Controls the main game loop and user interactions.

### Pet Classes
- **`Pet`**: Base class with `feed`, `play`, and `rest` methods.
- **`Dog`, `Cat`, `Pig`, `Bunny`**: Derived classes with specific behaviors.

### File Handling (`FileHandler.cpp`)
- `saveToFile`: Writes pet data to `petsave.txt`.
- `loadFromFile`: Loads pet data and recreates objects.

### Exception Handling (`PetException.h`)
- Custom exceptions for invalid interactions (e.g., not enough energy to play).

## Future Enhancements
- **More Pet Types**: Add Fish, Bird, etc.
- **Advanced Interactions**: Add grooming, training, etc.
- **GUI**: Replace CLI with Qt or SFML.
- **Structured Save Format**: Switch to JSON or XML.
- **Pet Aging System**: Track pet age and evolving needs.

## License
This project is licensed under the MIT License.

## Author & Contributors
- [Aiden Braulio](https://github.com/Din0Din)
- [Ezra Mosegui](https://github.com/EMosegui)
- [Jinn Rentsendorj](https://github.com/J-Rentsendorj)


