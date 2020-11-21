/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Comp_4013
*/

#include "Comp_4013.hpp"

nts::Comp_4013::Comp_4013()
{
    for (size_t i = 0; i < 14; i++) {
        _value.push_back(nts::UNDEFINED);
        this->_pin[i] = NULL;
        _link[i] = 0;
    }
}

nts::Comp_4013::~Comp_4013()
{
}

nts::Tristate nts::Comp_4013::compute(std::size_t pin)
{
    nts::Tristate CL;
    nts::Tristate R;
    nts::Tristate D;
    nts::Tristate S;

    if (pin != 1 && pin != 2 && pin != 12 && pin != 13)
        throw PinError("Invalid compute pin.");
    if (pin < 3) {
        CL = _pin[2]->compute(_link[2]);
        R = _pin[3]->compute(_link[3]);
        D = _pin[4]->compute(_link[4]);
        S = _pin[5]->compute(_link[5]);
    } else {
        CL = _pin[10]->compute(_link[10]);
        R = _pin[9]->compute(_link[9]);
        D = _pin[8]->compute(_link[8]);
        S = _pin[7]->compute(_link[7]);
    }
    if (R == nts::UNDEFINED || S == nts::UNDEFINED) {
        return nts::UNDEFINED;
    }
    if (R == nts::TRUE && S == nts::TRUE) {
        _value.at((pin < 3) ? 0 : 12) = nts::TRUE;
        _value.at((pin < 3) ? 1 : 11) = nts::TRUE;
        return nts::TRUE;
    }
    else if (R == nts::TRUE || (CL == nts::TRUE && D == nts::FALSE)) {
        _value.at((pin < 3) ? 0 : 12) = nts::FALSE;
        _value.at((pin < 3) ? 1 : 11) = nts::TRUE;
    }
    else if (S == nts::TRUE || (CL == nts::TRUE && D == nts::TRUE)) {
        _value.at((pin < 3) ? 0 : 12) = nts::TRUE;
        _value.at((pin < 3) ? 1 : 11) = nts::FALSE;
    }
    else if (D == nts::UNDEFINED || CL == nts::UNDEFINED)
        return nts::UNDEFINED;
    return _value.at(pin - 1);
}

void nts::Comp_4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 13 || pin == 7)
        throw PinError("Invalid pin.");
    else if ((pin - 1) < 14 && this->_pin[pin - 1] == NULL) {
        _link[pin - 1] = otherPin;
        this->_pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    }
}

void nts::Comp_4013::dump() const
{
    std::cout << "Comp_4013" << std::endl;
    for (size_t i = 0; i < 14; i++) {
        std::cout << "    pin #" << i << ": " << (((this->_pin[i]) == NULL) ? "NULL" : "linked") << std::endl;
    }
}

nts::Tristate nts::Comp_4013::getValue() const
{
    return nts::UNDEFINED;
}

void nts::Comp_4013::setValue(std::string const &)
{
}