// Header file that includes the Pet header file and creates a derived class with a new function and string 
#ifndef Pig_H
#define Pig_H

#include "Pet.h"

class Pig : public Pet {
public:
    Pig(std::string name);
    void react() const override;
    std::string toString() const override;
};

#endif
