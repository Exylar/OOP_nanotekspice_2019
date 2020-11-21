/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
    _constructors["input"] = [](const std::string &value){ return std::make_unique<nts::Input>(value); };
    _constructors["output"] = [](const std::string &){ return std::make_unique<nts::Output>(); };
    _constructors["clock"] = [](const std::string &value){ return std::make_unique<nts::Input>(value); };
    _constructors["true"] = [](const std::string &){ return std::make_unique<nts::True>(); };
    _constructors["false"] = [](const std::string &){ return std::make_unique<nts::False>(); };
    _constructors["and"] = [](const std::string &){ return std::make_unique<nts::And>(); };
    _constructors["or"] = [](const std::string &){ return std::make_unique<nts::Or>(); };
    _constructors["xor"] = [](const std::string &){ return std::make_unique<nts::Xor>(); };
    _constructors["nor"] = [](const std::string &){ return std::make_unique<nts::Nor>(); };
    _constructors["nand"] = [](const std::string &){ return std::make_unique<nts::Nand>(); };
    _constructors["not"] = [](const std::string &){ return std::make_unique<nts::Not>(); };
    _constructors["sum"] = [](const std::string &){ return std::make_unique<nts::Sum>(); };
    _constructors["4081"] = [](const std::string &){ return std::make_unique<nts::Comp_4081>(); };
    _constructors["4001"] = [](const std::string &){ return std::make_unique<nts::Comp_4001>(); };
    _constructors["4071"] = [](const std::string &){ return std::make_unique<nts::Comp_4071>(); };
    _constructors["4011"] = [](const std::string &){ return std::make_unique<nts::Comp_4011>(); };
    _constructors["4030"] = [](const std::string &){ return std::make_unique<nts::Comp_4030>(); };
    _constructors["4069"] = [](const std::string &){ return std::make_unique<nts::Comp_4069>(); };
    _constructors["4008"] = [](const std::string &){ return std::make_unique<nts::Comp_4008>(); };
    _constructors["4514"] = [](const std::string &){ return std::make_unique<nts::Comp_4514>(); };
    _constructors["4013"] = [](const std::string &){ return std::make_unique<nts::Comp_4013>(); };
    _constructors["4040"] = [](const std::string &){ return std::make_unique<nts::Comp_4040>(); };
}

nts::Factory::~Factory()
{
}
    
std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type, const std::string &value)
{
    if (_constructors.find(type) == _constructors.end())
        throw ComponentError("Unknown component.");
    return _constructors[type](value);
}