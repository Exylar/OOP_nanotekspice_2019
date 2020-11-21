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

Test(d_latch, allUndifined)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/d_latch.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/d_latch.nts");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "nout=U\nout=U\n");
}

Test(d_latch, all0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/d_latch.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/d_latch.nts");
    circuit.setValue("clock", "1");
    circuit.setValue("data", "0");
    circuit.setValue("set", "0");
    circuit.setValue("reset", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "nout=1\nout=0\n");
}

Test(d_latch, dump0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/d_latch.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/d_latch.nts");
    circuit.setValue("clock", "0");
    circuit.setValue("data", "0");
    circuit.setValue("set", "0");
    circuit.setValue("reset", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.dump();
    cr_assert_eq(oss.getContent(), "Input - value: 1\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nComp_4013\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    pin #3: linked\n    pin #4: linked\n    pin #5: linked\n    pin #6: NULL\n    pin #7: NULL\n    pin #8: NULL\n    pin #9: NULL\n    pin #10: NULL\n    pin #11: NULL\n    pin #12: NULL\n    pin #13: NULL\nOutput - value: -1\n    pin #1: linked\nOutput - value: -1\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\n");
}