/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#include "True.hpp"

nts::True::True()
{
    _value = nts::Tristate::TRUE;
    this->_pin[0] = NULL;
    _link.first = 0;
    _link.second = 0;
}

nts::True::~True()
{
}

nts::Tristate nts::True::compute(std::size_t pin)
{
    if ((pin - 1) > 0) {
        throw PinError("Unknown pin.");
    }
    return _value;
}

void nts::True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void nts::True::dump() const
{
    std::cout << "TRUE - value: " << static_cast<int>(_value) << std::endl;
    std::cout << "    pin #1: " << (((this->_pin[0]) == NULL) ? "NULL" : "linked") << std::endl;
}

nts::Tristate nts::True::getValue() const
{
    return _value;
}

void nts::True::setValue(std::string const &)
{
}