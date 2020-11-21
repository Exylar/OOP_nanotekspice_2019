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

class OSRedirector
{
private:
    std::ostringstream _oss;
    std::streambuf *_backup;
    std::ostream &_c;

public:
    OSRedirector(std::ostream &c) : _c(c)
    {
        _backup = _c.rdbuf();
        _c.rdbuf(_oss.rdbuf());
    }

    ~OSRedirector()
    {
        _c.rdbuf(_backup);
    }

    const std::string getContent()
    {
        _oss << std::flush;
        return _oss.str();
    }
};

Test(Error, filenotfound)
{
    Circuit circuit;
    Parser parser(&circuit);

    cr_assert_throw(parser.checkFile("./tests/nts_files/error/simple/filenotfound.nts"), FileError)
}

Test(Error, WrongFile)
{
    Circuit circuit;
    Parser parser(&circuit);

    cr_assert_throw(parser.checkFile("./tests/nts_files/error/simple/wrongfile.nts"), FileError)
}

Test(Error, WrongExtension)
{
    Circuit circuit;
    Parser parser(&circuit);

    cr_assert_throw(parser.checkFile("./tests/nts_files/error/error.txt"), FileError)
}

Test(Error, UnknownComponent)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/unknown.nts");
    cr_assert_throw(parser.parseNtsFile("./tests/nts_files/error/unknown.nts"), ComponentError)
}

Test(Error, SyntaxError)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/syntaxe_error.nts");
    cr_assert_throw(parser.parseNtsFile("./tests/nts_files/error/syntaxe_error.nts"), FileError)
}

Test(Error, Samename)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/samename.nts");
    cr_assert_throw(parser.parseNtsFile("./tests/nts_files/error/samename.nts"), ComponentError);
}

Test(Error, Namelink)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/errornamelink.nts");
    cr_assert_throw(parser.parseNtsFile("./tests/nts_files/error/errornamelink.nts"), ComponentError);
}

Test(Error, notinput)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/and.nts");
    parser.parseNtsFile("./tests/nts_files/simple/and.nts");
    cr_assert_throw(circuit.setInput("c", "1"), ComponentError)
}

Test(Error, notValue)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/simple/and.nts");
    parser.parseNtsFile("./tests/nts_files/simple/and.nts");
    cr_assert_throw(circuit.setValue("c", "1"), ComponentError)
}

Test(Error, andinvalidcompute)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/and/and_error_compute_pin.nts");
    parser.parseNtsFile("./tests/nts_files/error/and/and_error_compute_pin.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, andpinnotlink)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/and/and_pin_not_link.nts");
    parser.parseNtsFile("./tests/nts_files/error/and/and_pin_not_link.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, andunknowpin)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/and/and_unknown_pin.nts");
    cr_assert_throw(parser.parseNtsFile("./tests/nts_files/error/and/and_unknown_pin.nts"), PinError);
}

Test(Error, orinvalidcompute)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/or/error_compute_pin.nts");
    parser.parseNtsFile("./tests/nts_files/error/or/error_compute_pin.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, orpinnotlink)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/or/pin_not_link.nts");
    parser.parseNtsFile("./tests/nts_files/error/or/pin_not_link.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, orunknowpin)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/or/error_compute_pin.nts");
    cr_assert_throw(parser.parseNtsFile("./tests/nts_files/error/or/unknown_pin.nts"), PinError);
}

Test(Error, norinvalidcompute)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/nor/error_compute_pin.nts");
    parser.parseNtsFile("./tests/nts_files/error/nor/error_compute_pin.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, norpinnotlink)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/nor/pin_not_link.nts");
    parser.parseNtsFile("./tests/nts_files/error/nor/pin_not_link.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, norunknowpin)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/nor/error_compute_pin.nts");
    cr_assert_throw(parser.parseNtsFile("./tests/nts_files/error/nor/unknown_pin.nts"), PinError);
}

Test(Error, nandinvalidcompute)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/nand/error_compute_pin.nts");
    parser.parseNtsFile("./tests/nts_files/error/nand/error_compute_pin.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, nandpinnotlink)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/nand/pin_not_link.nts");
    parser.parseNtsFile("./tests/nts_files/error/nand/pin_not_link.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, nandunknowpin)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/nand/error_compute_pin.nts");
    cr_assert_throw(parser.parseNtsFile("./tests/nts_files/error/nand/unknown_pin.nts"), PinError);
}

Test(Error, xorinvalidcompute)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/xor/error_compute_pin.nts");
    parser.parseNtsFile("./tests/nts_files/error/xor/error_compute_pin.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, xorpinnotlink)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/xor/pin_not_link.nts");
    parser.parseNtsFile("./tests/nts_files/error/xor/pin_not_link.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, xorunknowpin)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/xor/error_compute_pin.nts");
    cr_assert_throw(parser.parseNtsFile("./tests/nts_files/error/xor/unknown_pin.nts"), PinError);
}

Test(Error, notinvalidcompute)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/not/error_compute_pin.nts");
    parser.parseNtsFile("./tests/nts_files/error/not/error_compute_pin.nts");
    circuit.setInput("a", "1");
    circuit.setInput("b", "1");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, notpinnotlink)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/not/pin_not_link.nts");
    parser.parseNtsFile("./tests/nts_files/error/not/pin_not_link.nts");
    cr_assert_throw(circuit.simulate(), PinError);
}

Test(Error, notunknowpin)
{
    Circuit circuit;
    Parser parser(&circuit);

    parser.checkFile("./tests/nts_files/error/not/error_compute_pin.nts");
    cr_assert_throw(parser.parseNtsFile("./tests/nts_files/error/not/unknown_pin.nts"), PinError);
}