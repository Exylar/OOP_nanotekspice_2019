/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Not
*/

#include "Not.hpp"

nts::Not::Not()
{
    for (size_t i = 0; i < 2; i++) {
        this->_value.push_back(nts::UNDEFINED);
        this->_pin[i] = NULL;
        _link[i] = 0;
    }
}

nts::Not::~Not()
{
}

nts::Tristate nts::Not::compute(std::size_t pin)
{
    if (pin != 2) {
        throw PinError("Invalid compute pin.");
    }
    else if (_pin[0] == NULL) {
        throw PinError("One or severals pins are not linked.");
    }
    _value.at(0) = _pin[0]->compute(_link[0]);
    if (_value.at(0) == nts::TRUE)
        return nts::FALSE;
    else
        return nts::TRUE;
}

void nts::Not::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if ((pin - 1) > 1) {
        throw PinError("Unknown pin.");
    }
    else if (this->_pin[pin - 1] == NULL) {
        _link[pin - 1] = otherPin;
        this->_pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    }
}

void nts::Not::dump() const
{
    std::cout << "Not" << std::endl;
    for (size_t i = 0; i < 2; i++)
        std::cout << "    pin #" << i << ": " << (((this->_pin[i]) == NULL) ? "NULL" : "linked") << std::endl;
}

nts::Tristate nts::Not::getValue() const
{
    return nts::UNDEFINED;
}

void nts::Not::setValue(std::string const &)
{
}