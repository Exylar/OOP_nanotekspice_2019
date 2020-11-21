/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include <iostream>
#include <string>
#include <utility>
#include "IComponent.hpp"
#include "Errors.hpp"

namespace nts
{
    class True : public IComponent {
        public:
            True();
            virtual ~True();
            virtual nts::Tristate compute(std::size_t pin = 1);
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            virtual void dump() const;
            virtual nts::Tristate getValue() const;
            virtual void setValue(std::string const &value);
        private:
            nts::Tristate _value;
            IComponent *_pin[1];
            std::pair<size_t, size_t> _link;
    };
}

#endif /* TRUE_HPP_ */