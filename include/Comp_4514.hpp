/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Comp_4514
*/

#ifndef COMP_4514_HPP_
#define COMP_4514_HPP_

#include <iostream>
#include <string>
#include <map>
#include <cmath>
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
    class Comp_4514 : public IComponent {
        public:
            Comp_4514();
            virtual ~Comp_4514();
            virtual nts::Tristate compute(std::size_t pin = 1);
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            virtual void dump() const;
            virtual nts::Tristate getValue() const;
            virtual void setValue(std::string const &value);
        private:
            size_t _value;
            IComponent *_pin[24];
            std::map<size_t, size_t> _link;
    };
}

#endif /* !COMP_4514_HPP_ */
