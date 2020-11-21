/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Errors.hpp"

Errors::Errors(const std::string &message)
{
    this->_message = message;
}

const char* Errors::what() const noexcept
{
    return _message.c_str();
}

FileError::FileError(const std::string &message) : Errors(message) {}

CircuitFileError::CircuitFileError(const std::string &message) : Errors(message) {}

ComponentError::ComponentError(const std::string &message) : Errors(message) {}

PinError::PinError(const std::string &message) : Errors(message) {}

InputError::InputError(const std::string &message) : Errors(message) {}

OutputError::OutputError(const std::string &message) : Errors(message) {}

ChipsetError::ChipsetError(const std::string &message) : Errors(message) {}