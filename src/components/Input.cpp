/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#include "Input.hpp"

nts::Input::Input(const std::string &value)
{
    if (value == "0")
        _value = nts::Tristate::FALSE;
    else if (value == "1")
        _value = nts::Tristate::TRUE;
    else
        _value = nts::Tristate::UNDEFINED;
    this->_pin[0] = NULL;
    _link.first = 0;
    _link.second = 0;
}

nts::Input::~Input()
{
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    if ((pin - 1) > 0) {
        throw PinError("Unknown pin.");
    }
    return _value;
}

void nts::Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if ((pin - 1) == 0 && this->_pin[pin - 1] == NULL) {
        _link.first = pin;
        _link.second = otherPin;
        this->_pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    }
    else if ((pin - 1) > 0) {
        throw PinError("Unknown pin.");
    }
}

void nts::Input::dump() const
{
    std::cout << "Input - value: " << static_cast<int>(_value) << std::endl;
    std::cout << "    pin #1: " << (((this->_pin[0]) == NULL) ? "NULL" : "linked") << std::endl;
}

nts::Tristate nts::Input::getValue() const
{
    return _value;
}

void nts::Input::setValue(std::string const &value)
{
    if (value == "0") {
        _value = nts::Tristate::FALSE;
    }
    else if (value == "1") {
        _value = nts::Tristate::TRUE;
    } else {
        throw InputError("Input value: Wrong value.");
    }
}