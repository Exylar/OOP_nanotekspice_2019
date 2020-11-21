/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Comp_4008
*/

#include "Comp_4008.hpp"

nts::Comp_4008::Comp_4008()
{
    nts::Factory factory;
    
    for (size_t i = 0; i < 4; i++) {
        _gates.push_back(factory.createComponent("sum", "-1"));
    }
    _gates.at(0)->setLink(5, *_gates.at(1), 3);
    _gates.at(1)->setLink(5, *_gates.at(2), 3);
    _gates.at(2)->setLink(5, *_gates.at(3), 3);
}

nts::Comp_4008::~Comp_4008()
{
}

nts::Tristate nts::Comp_4008::compute(std::size_t pin)
{
    if (pin < 10 && pin > 14) {
        throw PinError("Invalid compute pin.");
    }
    if (pin == 14) {
        return _gates.at(3)->compute(5);
    } else {
        return _gates.at(pin - 10)->compute(4);
    }
}

void nts::Comp_4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    std::vector<int> index_imp = {3, 2, 1, 0};
    std::vector<int> index_p = {2, 1, 0};
    if (pin == 8 || pin >= 16) {
        throw PinError("Invalid link pin.");
    }
    if (pin <= 7 && (pin % 2 == 1)) {
        _gates.at(index_imp.at(pin / 2))->setLink(1, other, otherPin);
    }
    else if (pin <= 7 && (pin % 2 == 0)) {
        _gates.at(index_p.at((pin / 2) - 1))->setLink(2, other, otherPin);
    }
    else if (pin == 9) {
        _gates.at(0)->setLink(3, other, otherPin);
    }
    else if (pin >= 10 && pin <= 13) {
        _gates.at(pin - 10)->setLink(4, other, otherPin);
    }
    else if (pin == 14) {
        _gates.at(3)->setLink(5, other, otherPin);
    }
    else if (pin == 15) {
        _gates.at(3)->setLink(2, other, otherPin);
    }
}

void nts::Comp_4008::dump() const
{
    std::cout << "Comp_4008" << std::endl;
    for (size_t i = 0; i < 4; i++) {
        std::cout << "    comp #" << i << ": " << std::endl;
        _gates.at(i)->dump();
    }
}

nts::Tristate nts::Comp_4008::getValue() const
{
    return nts::UNDEFINED;
}

void nts::Comp_4008::setValue(std::string const &)
{
}