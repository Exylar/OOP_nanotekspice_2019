/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Comp_4514
*/

#include "Comp_4514.hpp"

nts::Comp_4514::Comp_4514()
{
    _value = 0;
    for (size_t i = 0; i < 24; i++) {
        this->_pin[i] = NULL;
        _link[i] = 0;
    }
}

nts::Comp_4514::~Comp_4514()
{
}

nts::Tristate nts::Comp_4514::compute(std::size_t pin)
{
    std::vector<size_t> pinOrder = {{11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15}};
    std::vector<size_t> inputPin = {{1, 2, 20, 21}};

    if (pin <= 3 || pin == 12 || pin >= 21)
        throw PinError("Invalid compute pin.");
    if (_pin[22]->compute(_link[22]) == nts::TRUE)
        return nts::FALSE;
    if (_pin[22]->compute(_link[22]) == nts::UNDEFINED || _pin[0]->compute(_link[0]) == nts::UNDEFINED)
        return nts::FALSE;
    if (_pin[0]->compute(_link[0]) == nts::FALSE) {
        if (pin == pinOrder[_value])
            return nts::TRUE;
        else
            return nts::FALSE;
    } else {
        for (size_t i = 0; i < 4; i++) {
            if (_pin[inputPin[i]]->compute(_link[inputPin[i]]) == nts::UNDEFINED)
                return nts::UNDEFINED;
        }
        _value = 0;
        for (size_t i = 0; i < 4; i++) {
            if (_pin[inputPin[i]]->compute(_link[inputPin[i]]) == nts::TRUE)
                _value += std::pow(2, i);
        }
        if (pin == pinOrder[_value])
            return nts::TRUE;
        else
            return nts::FALSE;
    }
}

void nts::Comp_4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if ((pin - 1) < 24 && this->_pin[pin - 1] == NULL) {
        _link[pin - 1] = otherPin;
        this->_pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    }
    else if ((pin - 1) > 23) {
        throw PinError("Unknown pin.");
    }
}

void nts::Comp_4514::dump() const
{
    std::cout << "Comp_4514" << std::endl;
    for (size_t i = 0; i < 24; i++) {
        std::cout << "    pin #" << i << ": " << (((this->_pin[i]) == NULL) ? "NULL" : "linked") << std::endl;
    }
}

nts::Tristate nts::Comp_4514::getValue() const
{
    return nts::UNDEFINED;
}

void nts::Comp_4514::setValue(std::string const &)
{
}