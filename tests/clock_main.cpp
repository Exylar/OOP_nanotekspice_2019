/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"
#include <ostream>
#include <iostream>

class OSRedirector {
    private:
        std::ostringstream _oss;
        std::streambuf *_backup;
        std::ostream &_c;


    public:
        OSRedirector(std::ostream &c) : _c(c) {
            _backup = _c.rdbuf();
            _c.rdbuf(_oss.rdbuf());
        }

        ~OSRedirector() {
            _c.rdbuf(_backup);
        }

        const std::string getContent() {
            _oss << std::flush;
            return _oss.str();
        }
};

Test(Clock, ClockUndifined)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/clock.nts");
    parser.parseNtsFile("./tests/nts_files/simple/clock.nts");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=U\n");
}

Test(Clock, Clock0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/clock.nts");
    parser.parseNtsFile("./tests/nts_files/simple/clock.nts");
    circuit.setValue("a", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=0\n");
}

Test(Clock, Clock1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/clock.nts");
    parser.parseNtsFile("./tests/nts_files/simple/clock.nts");
    circuit.setValue("a", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=1\n");
}

Test(Clock, Clock0_simulate)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/clock.nts");
    parser.parseNtsFile("./tests/nts_files/simple/clock.nts");
    circuit.setValue("a", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=1\n");
}

Test(Clock, Clock1_simulate)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/clock.nts");
    parser.parseNtsFile("./tests/nts_files/simple/clock.nts");
    circuit.setValue("a", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=0\n");
}

Test(Clock, ClockDump1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/clock.nts");
    parser.parseNtsFile("./tests/nts_files/simple/clock.nts");
    circuit.setValue("a", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.dump();
    cr_assert_eq(oss.getContent(), "Input - value: 0\n    pin #1: linked\nOutput - value: 1\n    pin #1: linked\n");
}

Test(Clock, ClockDump0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/clock.nts");
    parser.parseNtsFile("./tests/nts_files/simple/clock.nts");
    circuit.setValue("a", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.dump();
    cr_assert_eq(oss.getContent(), "Input - value: 1\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\n");
}

Test(Clock, ClockDump1_simulate)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/clock.nts");
    parser.parseNtsFile("./tests/nts_files/simple/clock.nts");
    circuit.setValue("a", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.simulate();
    circuit.dump();
    cr_assert_eq(oss.getContent(), "Input - value: 1\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\n");
}

Test(Clock, ClockDump0_simulate)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/clock.nts");
    parser.parseNtsFile("./tests/nts_files/simple/clock.nts");
    circuit.setValue("a", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.simulate();
    circuit.dump();
    cr_assert_eq(oss.getContent(), "Input - value: 0\n    pin #1: linked\nOutput - value: 1\n    pin #1: linked\n");
}