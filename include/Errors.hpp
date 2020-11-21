/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef OOP_NANOTEKSPICE_2019_ERRORS_HPP
#define OOP_NANOTEKSPICE_2019_ERRORS_HPP

#include <string>

class Errors : public std::exception {
    public:
        Errors(std::string const &message);
        const char *what() const noexcept;
    private:
        std::string _message = "Message";
};

class FileError : public Errors {
    public:
        FileError(std::string const &message);
};

class CircuitFileError : public Errors {
    public:
        CircuitFileError(std::string const &message);
};

class ComponentError : public Errors {
    public:
        ComponentError(std::string const &message);
};

class PinError : public Errors {
    public:
        PinError(std::string const &message);
};

class InputError : public Errors {
    public:
        InputError(std::string const &message);
};

class OutputError : public Errors {
    public:
        OutputError(std::string const &message);
};

class ChipsetError : public Errors {
    public:
        ChipsetError(std::string const &message);
};

#endif //OOP_NANOTEKSPICE_2019_ERRORS_HPP
