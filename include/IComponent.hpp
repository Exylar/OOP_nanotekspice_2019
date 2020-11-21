/*
** EPITECH PROJECT, 2020
** nanotekspice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <string>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    
    class IComponent
    {
        public:
            virtual ~IComponent() = default;
        public:
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual nts::Tristate getValue() const = 0;
            virtual void setValue(std::string const &value) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
