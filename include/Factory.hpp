/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <utility>
#include <string>
#include <memory>
#include <functional>
#include <unordered_map>
#include "IComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "False.hpp"
#include "True.hpp"
#include "And.hpp"
#include "Or.hpp"
#include "Xor.hpp"
#include "Nor.hpp"
#include "Nand.hpp"
#include "Not.hpp"
#include "Sum.hpp"
#include "Comp_4081.hpp"
#include "Comp_4001.hpp"
#include "Comp_4071.hpp"
#include "Comp_4011.hpp"
#include "Comp_4030.hpp"
#include "Comp_4069.hpp"
#include "Comp_4008.hpp"
#include "Comp_4514.hpp"
#include "Comp_4013.hpp"
#include "Comp_4040.hpp"
#include "Errors.hpp"

namespace nts
{
    class Factory {
    public:
        Factory();
        ~Factory();
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);
    private:
        std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>> _constructors;
    };
}


#endif /* !FACTORY_HPP_ */
