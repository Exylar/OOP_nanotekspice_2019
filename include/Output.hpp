/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include <iostream>
#include <string>
#include <utility>
#include "IComponent.hpp"
#include "Errors.hpp"

namespace nts
{
    class Output : public IComponent {
        public:
            Output();
            virtual ~Output();
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

#endif /* OUTPUT_HPP_ */