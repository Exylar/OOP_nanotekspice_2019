/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Comp_4040
*/

#include "Comp_4040.hpp"

nts::Comp_4040::Comp_4040()
{
    for (size_t i = 0; i < 16; i++) {
        this->_pin[i] = NULL;
        _link[i] = 0;
    }
    _value = 0;
    _clockState = nts::UNDEFINED;
}

nts::Comp_4040::~Comp_4040()
{
}

nts::Tristate nts::Comp_4040::compute(std::size_t pin)
{
    nts::Tristate CL;
    nts::Tristate R;
    std::vector<size_t> pinOrder = {{11, 5, 4, 6, 3, 2, 1, 0, 0, 0, 0, 8, 7, 9, 10}};
    int ret_val;

    if (pin < 1 || pin == 8 || pin == 10 || pin == 11 || pin > 15)
        throw PinError("Invalid compute pin.");
    CL = _pin[9]->compute(_link[9]);
    R = _pin[10]->compute(_link[10]);
    if (CL == nts::UNDEFINED || R == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (R == nts::TRUE)
        _value = 0;
    else if (CL == nts::FALSE && _clockState == nts::TRUE) {
        _value++;
    }
    _clockState = CL;
    ret_val = pinOrder[pin - 1];
    if ((_value >> ret_val) & 1)
        return nts::TRUE;
    else
        return nts::FALSE;
}

void nts::Comp_4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 15 || pin == 8)
        throw PinError("Invalid pin.");
    else if ((pin - 1) < 14 && this->_pin[pin - 1] == NULL) {
        _link[pin - 1] = otherPin;
        this->_pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    }
}

void nts::Comp_4040::dump() const
{
    std::cout << "Comp_4040" << std::endl;
    for (size_t i = 0; i < 14; i++) {
        std::cout << "    pin #" << i << ": " << (((this->_pin[i]) == NULL) ? "NULL" : "linked") << std::endl;
    }
}

nts::Tristate nts::Comp_4040::getValue() const
{
    return nts::UNDEFINED;
}

void nts::Comp_4040::setValue(std::string const &)
{
}