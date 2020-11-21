/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include "IComponent.hpp"
#include "Errors.hpp"

namespace nts
{
    class And : public IComponent {
        public:
            And();
            virtual ~And();
            virtual nts::Tristate compute(std::size_t pin = 3);
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            virtual void dump() const;
            virtual nts::Tristate getValue() const;
            virtual void setValue(std::string const &value);
        private:
            std::vector<nts::Tristate> _value;
            IComponent *_pin[3];
            std::map<size_t, size_t> _link;
    };
}

#endif /* AND_HPP_ */