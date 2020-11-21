/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Comp_4069
*/

#include "Comp_4069.hpp"

nts::Comp_4069::Comp_4069()
{
    nts::Factory factory;
    
    for (size_t i = 0; i < 6; i++) {
        _gates.push_back(factory.createComponent("not", "-1"));
    }
}

nts::Comp_4069::~Comp_4069()
{
}

nts::Tristate nts::Comp_4069::compute(std::size_t pin)
{
    if (pin == 7 || pin >= 14 || (pin % 2 != 0)) {
        throw PinError("Invalid compute pin.");
    }
    return _gates.at((pin / 2) - 1)->compute(2);
}

void nts::Comp_4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 7 || pin >= 14) {
        throw PinError("Invalid link pin.");
    }
    if (pin % 2 == 0) {
        _gates.at((pin / 2) - 1)->setLink(2, other, otherPin);
    }
    else if (pin % 2 == 1) {
        if (pin < 7) {
            _gates.at(pin / 2)->setLink(1, other, otherPin);
        } else {
            _gates.at((pin / 2) - 1)->setLink(1, other, otherPin);
        }
    }
}

void nts::Comp_4069::dump() const
{
    std::cout << "Comp_4069" << std::endl;
    for (size_t i = 0; i < 6; i++) {
        std::cout << "    comp #" << i << ": " << std::endl;
        _gates.at(i)->dump();
    }
}

nts::Tristate nts::Comp_4069::getValue() const
{
    return nts::UNDEFINED;
}

void nts::Comp_4069::setValue(std::string const &)
{
}