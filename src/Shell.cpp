/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Shell.hpp"

volatile sig_atomic_t stopFlag = false;

void sigintsignal(int signalnum)
{
    signalnum = signalnum;
    stopFlag = true;
}

Shell::Shell(Circuit *circuit)
{
    this->_circuit = circuit;
}

void Shell::prompt()
{
    std::string line;
    int exit = 0;

    while (!(exit)) {
        std::cout << "> ";
        std::cin >> line;
        if (line == "exit" || std::cin.eof())
            exit = this->exit();
        else if (line == "display")
            this->display();
        else if (line == "simulate")
            this->simulate();
        else if (line == "loop")
            this->loop();
        else if (line == "dump")
            this->dump();
        else if (line.find("=") != std::string::npos)
            this->input(line);
        else
            std::cout << line << ": command not found." << std::endl;
    }
}

bool Shell::exit() const
{
    return 1;
}

void Shell::display() const
{
    this->_circuit->displayOutput();
}

void Shell::input(std::string &string)
{
    std::string input;
    std::string value;
    size_t pos = 0;

    pos = string.find("=");
    input = string.substr(0, pos);
    value = string.substr(pos + 1);
    if (!(value == "0" || value == "1"))
        throw InputError("Invalid value: valid value is 0 or 1.");
    this->_circuit->setInput(input, value);
}

void Shell::simulate() const
{
    this->_circuit->simulate();
}

void Shell::loop() const
{
    signal(SIGINT, sigintsignal);

    while (!(stopFlag)) {
        this->_circuit->simulate();
        this->display();
    }
    stopFlag = false;
}

void Shell::dump() const
{
    this->_circuit->dump();
}