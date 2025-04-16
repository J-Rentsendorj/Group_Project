#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>
#include "Pet.h"

void saveToFile(const std::vector<Pet*>& pets, const std::string& filename);
void loadFromFile(std::vector<Pet*>& pets, const std::string& filename);

#endif
