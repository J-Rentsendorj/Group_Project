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