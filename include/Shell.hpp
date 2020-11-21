/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef OOP_NANOTEKSPICE_2019_NANOTEKSPICE_HPP
#define OOP_NANOTEKSPICE_2019_NANOTEKSPICE_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <csignal>
#include "Circuit.hpp"
#include "IComponent.hpp"

class Shell {
    public:
        Shell(Circuit *circuit);
        ~Shell() = default;

        void prompt();
        bool exit() const;
        void display() const;
        void input(std::string &string);
        void simulate() const;
        void loop() const;
        void dump() const;
    private:
        Circuit *_circuit;
};

#endif //OOP_NANOTEKSPICE_2019_NANOTEKSPICE_HPP
