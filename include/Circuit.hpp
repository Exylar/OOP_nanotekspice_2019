/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef OOP_NANOTEKSPICE_2019_CIRCUIT_HPP
#define OOP_NANOTEKSPICE_2019_CIRCUIT_HPP

#include <memory>
#include <map>
#include <vector>
#include "IComponent.hpp"
#include "Factory.hpp"
#include "Errors.hpp"

class Circuit {
    public:
        Circuit();
        ~Circuit() = default;
        void addComponent(std::string const &name, std::string const &type);
        void setLinks(std::string const &name1, std::string const &pin1, std::string const &name2, std::string const &pin2);
        void setInput(std::string const &name, std::string const &value);
        void setValue(std::string const &name, std::string const &value);
        void orderOutput();
        void simulate();
        void dump() const;
        void displayOutput();
    private:
        std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
        std::vector<std::string> _inputs;
        std::vector<std::string> _outputs;
        std::vector<std::string> _clocks;
};

#endif //OOP_NANOTEKSPICE_2019_CIRCUIT_HPP