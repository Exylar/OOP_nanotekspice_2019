/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Comp_4069
*/

#ifndef COMP_4069_HPP_
#define COMP_4069_HPP_

#include <memory>
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include "IComponent.hpp"
#include "Errors.hpp"
#include "Factory.hpp"

namespace nts
{
    class Factory;
}

namespace nts
{
    class Comp_4069 : public IComponent {
        public:
            Comp_4069();
            virtual ~Comp_4069();
            virtual nts::Tristate compute(std::size_t pin = 2);
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            virtual void dump() const;
            virtual nts::Tristate getValue() const;
            virtual void setValue(std::string const &value);
        private:
            std::vector<std::unique_ptr<nts::IComponent>> _gates;
    };
}

#endif /* !COMP_4069_HPP_ */