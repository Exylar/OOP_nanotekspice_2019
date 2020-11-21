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

Test(simple_or, orUndifined)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/or.nts");
    parser.parseNtsFile("./tests/nts_files/simple/or.nts");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=0\n");
}

Test(simple_or, ora0b0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/or.nts");
    parser.parseNtsFile("./tests/nts_files/simple/or.nts");
    circuit.setValue("a", "0");
    circuit.setValue("b", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=0\n");
}


Test(simple_or, ora0b1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/or.nts");
    parser.parseNtsFile("./tests/nts_files/simple/or.nts");
    circuit.setValue("a", "0");
    circuit.setValue("b", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=1\n");
}

Test(simple_or, ora1b0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/or.nts");
    parser.parseNtsFile("./tests/nts_files/simple/or.nts");
    circuit.setValue("a", "1");
    circuit.setValue("b", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=1\n");
}

Test(simple_or, ora1b1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/or.nts");
    parser.parseNtsFile("./tests/nts_files/simple/or.nts");
    circuit.setValue("a", "1");
    circuit.setValue("b", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=1\n");
}
