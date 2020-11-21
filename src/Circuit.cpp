/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <algorithm>
#include "Circuit.hpp"

Circuit::Circuit() {}

void Circuit::addComponent(std::string const &name, std::string const &type)
{
    nts::Factory factory;
    std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator it;

    it = this->_components.find(name);
    if (it != _components.end())
        throw ComponentError("Several components share the same name.");
    this->_components[name] = factory.createComponent(type, "-1");
    if (type == "input")
        this->_inputs.push_back(name);
    else if (type == "output")
        this->_outputs.push_back(name);
    else if (type == "clock")
        this->_clocks.push_back(name);
}

void Circuit::setLinks(std::string const &name1, std::string const &pin1, std::string const &name2, std::string const &pin2)
{
    std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator it;

    it = this->_components.find(name1);
    if (it == _components.end())
        throw ComponentError("A component name is unknown.");
    else
        this->_components[name1]->setLink(atoi(pin1.c_str()), *this->_components[name2], atoi(pin2.c_str()));
}

void Circuit::setInput(std::string const &name, std::string const &value)
{
    auto it = std::find(this->_inputs.begin(), this->_inputs.end(), name);

    if (it == _inputs.end())
        throw ComponentError("This is not an input component.");
    else
        this->_components[name]->setValue(value);
}

void Circuit::setValue(std::string const &name, std::string const &value)
{
    auto it = std::find(this->_inputs.begin(), this->_inputs.end(), name);

    if (it == _inputs.end()) {
        auto it = std::find(this->_clocks.begin(), this->_clocks.end(), name);

        if (it == _clocks.end())
            throw ComponentError("Invalid component.");
        else
            this->_components[name]->setValue(value);
    }
    else
        this->_components[name]->setValue(value);
}

void Circuit::simulate()
{
    for (auto name : this->_outputs) {
        this->_components[name]->compute(1);
    }
    for (auto name : this->_clocks) {
        nts::Tristate value = this->_components[name]->getValue();
        if (value == nts::TRUE)
            this->_components[name]->setValue("0");
        else
            this->_components[name]->setValue("1");
    }
}

void Circuit::dump() const
{
    for (auto const& x : this->_components)
    {
        x.second->dump();
    }
}

void Circuit::orderOutput()
{
    std::sort(this->_outputs.begin(), this->_outputs.end());
}

void Circuit::displayOutput()
{
    for (auto name : this->_outputs) {
        std::cout << name << "=";
        nts::Tristate value = this->_components[name]->getValue();
        if (value == nts::UNDEFINED)
            std::cout << "U" << std::endl;
        else
            std::cout << static_cast<int>(value) << std::endl;
    }
}