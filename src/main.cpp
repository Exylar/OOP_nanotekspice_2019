/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include <memory>
#include <algorithm>
#include <map>
#include "IComponent.hpp"
#include "False.hpp"
#include "True.hpp"
#include "Output.hpp"
#include "Factory.hpp"
#include "Parser.hpp"
#include "Shell.hpp"

int launch(int argc, char **argv)
{
    Circuit circuit;
    Parser parser(&circuit);
    Shell shell(&circuit);

    try {
        parser.checkFile(std::string(argv[1]));
    }
    catch (FileError &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    try {
        parser.parseNtsFile(std::string(argv[1]));
    }
    catch (Errors &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    try {
        parser.parseInput(argc, argv);
    }
    catch (Errors &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    circuit.orderOutput();
    try {
        circuit.simulate();
    }
    catch (Errors &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    circuit.displayOutput();
    try {
        shell.prompt();
    }
    catch (Errors &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 84;
    else
        return launch(argc, argv);
}