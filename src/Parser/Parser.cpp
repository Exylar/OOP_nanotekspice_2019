/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Parser.hpp"

Parser::Parser(Circuit *circuit)
{
    this->_circuit = circuit;
}

void Parser::checkFile(std::string const filename)
{
    std::string extension;
    std::string string(filename);

    if (!(std::ifstream(filename)))
        throw FileError(filename + ": file not found.");
    extension = string.substr(string.find_last_of("."), 4);
    if (extension != ".nts")
        throw FileError(filename + ": wrong extension file.");
}

void Parser::parseNtsFile(std::string const filename)
{
    std::string content;
    std::ifstream fs(filename);
    std::string chipsets;
    std::string links;
    int value = 0;

    while (std::getline(fs, content)) {
        if (content.find("#") == std::string::npos) {
            value = (content.find(".chipsets") != std::string::npos) ? 1 : value;
            value = (content.find(".links") != std::string::npos) ? 2 : value;
            if (value == 1 && content.find(".chipsets") == std::string::npos)
                chipsets += content + " ";
            else if (value == 2 && content.find(".links") == std::string::npos)
                links += content + " ";
        }
    }
    if (value != 2)
        throw FileError("The circuit file includes one or several lexical or syntactic errors.");
    createComposent(chipsets);
    createLinks(links);
}

void Parser::createComposent(std::string chipsets)
{
    std::regex expr("(\\w+)\\s+(\\w+)");
    std::smatch match;
    std::string name;
    std::string type;
    int i = 0;

    while (std::regex_search(chipsets, match, expr)) {
        for (auto x:match) {
            type = (i == 1) ? x : type;
            name = (i == 2) ? x : name;
            i++;
        }
        i = 0;
        chipsets = match.suffix().str();
        this->_circuit->addComponent(name, type);
    }
}

void Parser::createLinks(std::string links)
{
    std::regex expr("(\\w+)\\W(\\w+)\\s+(\\w+)\\W(\\w+)");
    std::smatch match;
    std::string name1;
    std::string pin1;
    std::string name2;
    std::string pin2;
    int i = 0;

    while (std::regex_search(links, match, expr)) {
        for (auto x:match) {
            name1 = (i == 1) ? x : name1;
            pin1 = (i == 2) ? x : pin1;
            name2 = (i == 3) ? x : name2;
            pin2 = (i == 4) ? x : pin2;
            i++;
        }
        i = 0;
        links = match.suffix().str();
        this->_circuit->setLinks(name1, pin1, name2, pin2);
    }
}

void Parser::parseInput(int argc, char **argv)
{
    std::string string;
    std::string input;
    std::string value;
    size_t pos = 0;
    int i = 2;

    while (i < argc) {
        string = std::string(argv[i]);
        pos = string.find("=");
        input = string.substr(0, pos);
        value = string.substr(pos + 1);
        if (!(value == "0" || value == "1"))
            throw InputError("Invalid value: valid value is 0 or 1.");
        this->_circuit->setValue(input, value);
        i++;
    }
}