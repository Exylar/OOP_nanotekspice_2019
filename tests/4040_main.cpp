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

Test(counter, allUndifined)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/counter.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/counter.nts");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "o0=U\no1=U\no10=U\no11=U\no2=U\no3=U\no4=U\no5=U\no6=U\no7=U\no8=U\no9=U\n");
}

Test(counter, all0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/counter.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/counter.nts");
    circuit.setValue("clock", "0");
    circuit.setInput("reset", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "o0=0\no1=0\no10=0\no11=0\no2=0\no3=0\no4=0\no5=0\no6=0\no7=0\no8=0\no9=0\n");
}

Test(counter, all1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/counter.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/counter.nts");
    circuit.setValue("clock", "1");
    circuit.setInput("reset", "1");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "o0=0\no1=0\no10=0\no11=0\no2=0\no3=0\no4=0\no5=0\no6=0\no7=0\no8=0\no9=0\n");
}

Test(counter, dump1)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/counter.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/counter.nts");
    circuit.setValue("clock", "1");
    circuit.setInput("reset", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.dump();
    cr_assert_eq(oss.getContent(), "Input - value: 0\n    pin #1: linked\nComp_4040\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    pin #3: linked\n    pin #4: linked\n    pin #5: linked\n    pin #6: linked\n    pin #7: NULL\n    pin #8: linked\n    pin #9: linked\n    pin #10: linked\n    pin #11: linked\n    pin #12: linked\n    pin #13: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\n");
}
