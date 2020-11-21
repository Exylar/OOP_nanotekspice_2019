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

Test(decoder, allUndifined)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/decoder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/decoder.nts");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s0=0\ns1=0\ns10=0\ns11=0\ns12=0\ns13=0\ns14=0\ns15=0\ns2=0\ns3=0\ns4=0\ns5=0\ns6=0\ns7=0\ns8=0\ns9=0\n");
}

Test(decoder, all0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/decoder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/decoder.nts");
    circuit.setInput("a0", "0");
    circuit.setInput("a1", "0");
    circuit.setInput("a2", "0");
    circuit.setInput("a3", "0");
    circuit.setInput("strobe", "0");
    circuit.setInput("inhibit", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.displayOutput();
    cr_assert_eq(oss.getContent(), "s0=1\ns1=0\ns10=0\ns11=0\ns12=0\ns13=0\ns14=0\ns15=0\ns2=0\ns3=0\ns4=0\ns5=0\ns6=0\ns7=0\ns8=0\ns9=0\n");
}

Test(decoder, dump0)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/combinatory/decoder.nts");
    parser.parseNtsFile("./tests/nts_files/combinatory/decoder.nts");
    circuit.setInput("a0", "0");
    circuit.setInput("a1", "0");
    circuit.setInput("a2", "0");
    circuit.setInput("a3", "0");
    circuit.setInput("strobe", "0");
    circuit.setInput("inhibit", "0");
    circuit.orderOutput();
    circuit.simulate();
    circuit.dump();
    cr_assert_eq(oss.getContent(), "Input - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\nComp_4514\n    pin #0: linked\n    pin #1: linked\n    pin #2: linked\n    pin #3: linked\n    pin #4: linked\n    pin #5: linked\n    pin #6: linked\n    pin #7: linked\n    pin #8: linked\n    pin #9: linked\n    pin #10: linked\n    pin #11: NULL\n    pin #12: linked\n    pin #13: linked\n    pin #14: linked\n    pin #15: linked\n    pin #16: linked\n    pin #17: linked\n    pin #18: linked\n    pin #19: linked\n    pin #20: linked\n    pin #21: linked\n    pin #22: linked\n    pin #23: NULL\nInput - value: 0\n    pin #1: linked\nOutput - value: 1\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nOutput - value: 0\n    pin #1: linked\nInput - value: 0\n    pin #1: linked\n");
}