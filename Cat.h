// Header file that include the Pet header file and creates a derived class of Pet with a new function and string
#ifndef Cat_H
#define Cat_H

#include "Pet.h"

class Cat : public Pet {
public:
    Cat(std::string name);
    void react() const override;
    std::string toString() const override;
};

#endif
