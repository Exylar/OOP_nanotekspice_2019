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

Test(inputs_and_gates, allUndifined)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/5_input_and_gate.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/5_input_and_gate.nts");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=0\n");
}

Test(inputs_and_gates, a0b0c0d0e0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/5_input_and_gate.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/5_input_and_gate.nts");
    circuit.setValue("a", "0");
    circuit.setValue("b", "0");
    circuit.setValue("c", "0");
    circuit.setValue("d", "0");
    circuit.setValue("e", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=0\n");
}

Test(inputs_and_gates, a1b1c1d1e1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/5_input_and_gate.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/5_input_and_gate.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    circuit.setInput("c", "1");
    circuit.setInput("d", "1");
    circuit.setInput("e", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s=1\n");
}

Test(inputs_and_gates, dump0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/5_input_and_gate.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/5_input_and_gate.nts");
    circuit.setInput("a", "0");
    circuit.setInput("b", "0");
    circuit.setInput("c", "0");
    circuit.setInput("d", "0");
    circuit.setInput("e", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.dump();
    cr_assert_eq(oss.getContent(), "Input - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nComp_4081\n    comp #0: \nAnd\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    comp #1: \nAnd\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    comp #2: \nAnd\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    comp #3: \nAnd\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\nOutput - value: 0\n    pin #1: linked\n");
}

Test(inputs_and_gates, dump1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/5_input_and_gate.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/5_input_and_gate.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    circuit.setInput("c", "1");
    circuit.setInput("d", "1");
    circuit.setInput("e", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.dump();
    cr_assert_eq(oss.getContent(), "Input - value: 1\n    pin #1: linked\nInput - value: 1\n    pin #1: linked\nInput - value: 1\n    pin #1: linked\nInput - value: 1\n    pin #1: linked\nInput - value: 1\n    pin #1: linked\nComp_4081\n    comp #0: \nAnd\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    comp #1: \nAnd\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    comp #2: \nAnd\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    comp #3: \nAnd\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\nOutput - value: 1\n    pin #1: linked\n");
}