/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#ifndef OOP_NANOTEKSPICE_2019_PARSER_HPP
#define OOP_NANOTEKSPICE_2019_PARSER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <map>
#include <string>
#include "Circuit.hpp"
#include "Errors.hpp"

class Parser {
    public:
        Parser(Circuit *circuit);
        ~Parser() = default;
        void checkFile(std::string const namefile);
        void parseNtsFile(std::string const namefile);
        void parseInput(int argc, char **argv);
        void createComposent(std::string chipsets);
        void createLinks(std::string links);
        void dump(std::string &chipsets, std::string &links);
    private:
        Circuit *_circuit;
};

#endif //OOP_NANOTEKSPICE_2019_PARSER_HPP
