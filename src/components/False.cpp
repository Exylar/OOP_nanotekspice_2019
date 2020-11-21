/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#include "False.hpp"

nts::False::False()
{
    _value = nts::Tristate::FALSE;
    this->_pin[0] = NULL;
    _link.first = 0;
    _link.second = 0;
}

nts::False::~False()
{
}

nts::Tristate nts::False::compute(std::size_t pin)
{
    if ((pin - 1) > 0) {
        throw PinError("Unknown pin.");
    }
    return _value;
}

void nts::False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void nts::False::dump() const
{
    std::cout << "FALSE - value: " << static_cast<int>(_value) << std::endl;
    std::cout << "    pin #1: " << (((this->_pin[0]) == NULL) ? "NULL" : "linked") << std::endl;
}

nts::Tristate nts::False::getValue() const
{
    return _value;
}

void nts::False::setValue(std::string const &)
{
}