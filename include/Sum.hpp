/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef OOP_NANOTEKSPICE_2019_SUM_HPP
#define OOP_NANOTEKSPICE_2019_SUM_HPP

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include "IComponent.hpp"
#include "Errors.hpp"

namespace nts
{
    class Sum : public IComponent {
    public:
        Sum();
        virtual ~Sum();
        virtual nts::Tristate compute(std::size_t pin = 4);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;
        virtual nts::Tristate getValue() const;
        virtual void setValue(std::string const &value);
    private:
        std::vector<nts::Tristate> _value;
        IComponent *_pin[5];
        std::map<size_t, size_t> _link;
    };
}


#endif //OOP_NANOTEKSPICE_2019_SUM_HPP
