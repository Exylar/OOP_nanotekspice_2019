/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Not
*/

#ifndef NOT_HPP_
#define NOT_HPP_

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include "IComponent.hpp"
#include "Errors.hpp"

namespace nts
{
    class Not : public IComponent {
        public:
            Not();
            virtual ~Not();
            virtual nts::Tristate compute(std::size_t pin = 2);
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            virtual void dump() const;
            virtual nts::Tristate getValue() const;
            virtual void setValue(std::string const &value);
        private:
            std::vector<nts::Tristate> _value;
            IComponent *_pin[2];
            std::map<size_t, size_t> _link;
    };
}

#endif /* !NOT_HPP_ */
