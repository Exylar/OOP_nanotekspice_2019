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

Test(adder, allUndifined)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/adder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/adder.nts");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "cout=0\no0=0\no1=0\no2=0\no3=0\n");
}

Test(adder, all0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/adder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/adder.nts");
    circuit.setInput("a0", "0");
    circuit.setInput("a1", "0");
    circuit.setInput("a2", "0");
    circuit.setInput("a3", "0");
    circuit.setInput("b0", "0");
    circuit.setInput("b1", "0");
    circuit.setInput("b2", "0");
    circuit.setInput("b3", "0");
    circuit.setInput("cin", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "cout=0\no0=0\no1=0\no2=0\no3=0\n");
}

Test(adder, all1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/adder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/adder.nts");
    circuit.setInput("a0", "1");
    circuit.setInput("a1", "1");
    circuit.setInput("a2", "1");
    circuit.setInput("a3", "1");
    circuit.setInput("b0", "1");
    circuit.setInput("b1", "1");
    circuit.setInput("b2", "1");
    circuit.setInput("b3", "1");
    circuit.setInput("cin", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "cout=1\no0=1\no1=1\no2=1\no3=1\n");
}

Test(adder, alla1cin0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/adder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/adder.nts");
    circuit.setInput("a0", "1");
    circuit.setInput("a1", "1");
    circuit.setInput("a2", "1");
    circuit.setInput("a3", "1");
    circuit.setInput("b0", "0");
    circuit.setInput("b1", "0");
    circuit.setInput("b2", "0");
    circuit.setInput("b3", "0");
    circuit.setInput("cin", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "cout=0\no0=1\no1=1\no2=1\no3=1\n");
}

Test(adder, alla1cin1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/adder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/adder.nts");
    circuit.setInput("a0", "1");
    circuit.setInput("a1", "1");
    circuit.setInput("a2", "1");
    circuit.setInput("a3", "1");
    circuit.setInput("b0", "0");
    circuit.setInput("b1", "0");
    circuit.setInput("b2", "0");
    circuit.setInput("b3", "0");
    circuit.setInput("cin", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "cout=1\no0=0\no1=0\no2=0\no3=0\n");
}

Test(adder, allb1cin0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/adder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/adder.nts");
    circuit.setInput("a0", "0");
    circuit.setInput("a1", "0");
    circuit.setInput("a2", "0");
    circuit.setInput("a3", "0");
    circuit.setInput("b0", "1");
    circuit.setInput("b1", "1");
    circuit.setInput("b2", "1");
    circuit.setInput("b3", "1");
    circuit.setInput("cin", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "cout=0\no0=1\no1=1\no2=1\no3=1\n");
}

Test(adder, allb1cin1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/adder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/adder.nts");
    circuit.setInput("a0", "0");
    circuit.setInput("a1", "0");
    circuit.setInput("a2", "0");
    circuit.setInput("a3", "0");
    circuit.setInput("b0", "1");
    circuit.setInput("b1", "1");
    circuit.setInput("b2", "1");
    circuit.setInput("b3", "1");
    circuit.setInput("cin", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "cout=1\no0=0\no1=0\no2=0\no3=0\n");
}

Test(adder, dump0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/adder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/adder.nts");
    circuit.setInput("a0", "0");
    circuit.setInput("a1", "0");
    circuit.setInput("a2", "0");
    circuit.setInput("a3", "0");
    circuit.setInput("b0", "0");
    circuit.setInput("b1", "0");
    circuit.setInput("b2", "0");
    circuit.setInput("b3", "0");
    circuit.setInput("cin", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.dump();
    cr_assert_eq(oss.getContent(), "Input - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nComp_4008\n    comp #0: \nSum\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    pin #3: linked\n    pin #4: linked\n    comp #1: \nSum\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    pin #3: linked\n    pin #4: linked\n    comp #2: \nSum\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    pin #3: linked\n    pin #4: linked\n    comp #3: \nSum\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    pin #3: linked\n    pin #4: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\n");
}