// Header file that includes the exception header file and creates a derived class that returns the string called message
#ifndef PETEXCEPTION_H
#define PETEXCEPTION_H

#include <exception>
#include <string>

class PetException : public std::exception {
    std::string message;

public:
    PetException(std::string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
