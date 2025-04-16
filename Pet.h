#ifndef PET_H
#define PET_H

#include <string>

class Pet {
protected:
    std::string name;
    int hunger;
    int energy;

public:
    Pet(std::string name);
    virtual ~Pet() {}

    virtual void feed();
    virtual void play();
    virtual void rest();
    virtual void react() const = 0;

    virtual std::string toString() const = 0;

    std::string getName() const;
    int getHunger() const;
    int getEnergy() const;
};

#endif
