/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "Shell.hpp"
#include <ostream>
#include <iostream>
#include <string>

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

Test(shell, and)
{
    OSRedirector oss(std::cout);
    Circuit circuit;
    Parser parser(&circuit);
    Shell shell(&circuit);

    std::string a = "a=1";
    std::string b = "b=1";

    parser.checkFile("./tests/nts_files/simple/and.nts");
    parser.parseNtsFile("./tests/nts_files/simple/and.nts");
    shell.input(a);
    shell.input(b);
    shell.simulate();
    shell.display();
    shell.exit();
    cr_assert_eq(oss.getContent(), "s=1\n");
}