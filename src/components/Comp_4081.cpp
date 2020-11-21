/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Comp_4081
*/

#include "Comp_4081.hpp"

nts::Comp_4081::Comp_4081()
{
    nts::Factory factory;
    
    for (size_t i = 0; i < 4; i++) {
        _gates.push_back(factory.createComponent("and", "-1"));
    }
}

nts::Comp_4081::~Comp_4081()
{
}

nts::Tristate nts::Comp_4081::compute(std::size_t pin)
{
    if (pin != 3 && pin != 4 && pin != 10 && pin != 11) {
        throw PinError("Invalid compute pin.");
    }
    if ((pin - 1) == 2) {
        return _gates.at(0)->compute(3);
    }
    else if ((pin - 1) == 3) {
        return _gates.at(1)->compute(3);
    }
    else if ((pin - 1) == 9) {
        return _gates.at(2)->compute(3);
    }
    else if ((pin - 1) == 10) {
        return _gates.at(3)->compute(3);
    }
    return nts::UNDEFINED;
}

void nts::Comp_4081::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if ((pin - 1) > 13) {
        throw PinError("Unknown pin.");
    }
    else if (pin == 7 || pin == 14) {
        throw PinError("You can't link electrical pin.");
    }
    else if ((pin - 1) == 0) {
        _gates.at(0)->setLink(1, other, otherPin);
    }
    else if ((pin - 1) == 1) {
        _gates.at(0)->setLink(2, other, otherPin);
    }
    else if ((pin - 1) == 2) {
        _gates.at(0)->setLink(3, other, otherPin);
    }
    else if ((pin - 1) == 3) {
        _gates.at(1)->setLink(3, other, otherPin);
    }
    else if ((pin - 1) == 4) {
        _gates.at(1)->setLink(2, other, otherPin);
    }
    else if ((pin - 1) == 5) {
        _gates.at(1)->setLink(1, other, otherPin);
    }
    else if ((pin - 1) == 7) {
        _gates.at(2)->setLink(1, other, otherPin);
    }
    else if ((pin - 1) == 8) {
        _gates.at(2)->setLink(2, other, otherPin);
    }
    else if ((pin - 1) == 9) {
        _gates.at(2)->setLink(3, other, otherPin);
    }
    else if ((pin - 1) == 10) {
        _gates.at(3)->setLink(3, other, otherPin);
    }
    else if ((pin - 1) == 11) {
        _gates.at(3)->setLink(2, other, otherPin);
    }
    else if ((pin - 1) == 12) {
        _gates.at(3)->setLink(1, other, otherPin);
    }
}

void nts::Comp_4081::dump() const
{
    std::cout << "Comp_4081" << std::endl;
    for (size_t i = 0; i < 4; i++) {
        std::cout << "    comp #" << i << ": " << std::endl;
        _gates.at(i)->dump();
    }
}

nts::Tristate nts::Comp_4081::getValue() const
{
    return nts::UNDEFINED;
}

void nts::Comp_4081::setValue(std::string const &)
{
}