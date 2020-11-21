/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#include "Output.hpp"

nts::Output::Output()
{
    _value = nts::Tristate::UNDEFINED; 
    this->_pin[0] = NULL;
    _link.first = 0;
    _link.second = 0;
}

nts::Output::~Output()
{
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    if ((pin - 1) > 0) {
        throw PinError("Unknown pin.");
    }
    if (_pin[pin - 1] == NULL) {
        throw PinError("Pin not linked.");
    }
    _value = _pin[pin - 1]->compute(_link.second);
    return _value;
}

void nts::Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void nts::Output::dump() const
{
    std::cout << "Output - value: " << static_cast<int>(_value) << std::endl;
    std::cout << "    pin #1: " << (((this->_pin[0]) == NULL) ? "NULL" : "linked") << std::endl;
}

nts::Tristate nts::Output::getValue() const
{
    return _value;
}

void nts::Output::setValue(std::string const &)
{
}