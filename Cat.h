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