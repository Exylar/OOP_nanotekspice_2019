/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Xor
*/

#include "Xor.hpp"

nts::Xor::Xor()
{
    for (size_t i = 0; i < 3; i++) {
        this->_value.push_back(nts::UNDEFINED);
        this->_pin[i] = NULL;
        _link[i] = 0;
    }
}

nts::Xor::~Xor()
{
}

nts::Tristate nts::Xor::compute(std::size_t pin)
{
    if (pin != 3) {
        throw PinError("Invalid compute pin.");
    }
    else if (_pin[0] == NULL || _pin[1] == NULL) {
        throw PinError("One or severals pins are not linked.");
    }
    _value.at(0) = _pin[0]->compute(_link[0]);
    _value.at(1) = _pin[1]->compute(_link[1]);
    if (_value.at(0) == nts::TRUE && _value.at(1) == nts::TRUE)
        return nts::FALSE;
    else if (_value.at(0) == nts::TRUE || _value.at(1) == nts::TRUE)
        return nts::TRUE;
    else
        return nts::FALSE;
}

void nts::Xor::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if ((pin - 1) > 2) {
        throw PinError("Unknown pin.");
    }
    else if (this->_pin[pin - 1] == NULL) {
        _link[pin - 1] = otherPin;
        this->_pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    }
}

void nts::Xor::dump() const
{
    std::cout << "Xor" << std::endl;
    for (size_t i = 0; i < 3; i++)
        std::cout << "    pin #" << i << ": " << (((this->_pin[i]) == NULL) ? "NULL" : "linked") << std::endl;
}

nts::Tristate nts::Xor::getValue() const
{
    return nts::UNDEFINED;
}

void nts::Xor::setValue(std::string const &)
{
}