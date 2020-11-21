/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Created by thomas1.bastien@epitech.eu
*/

#include "Sum.hpp"

nts::Sum::Sum()
{
    for (size_t i = 0; i < 5; i++) {
        this->_value.push_back(nts::UNDEFINED);
        this->_pin[i] = NULL;
        _link[i] = 0;
    }
}

nts::Sum::~Sum()
{
}

nts::Tristate nts::Sum::compute(std::size_t pin)
{
    if (pin != 4 && pin != 5) {
        throw PinError("Invalid compute pin.");
    }
    else if (_pin[0] == NULL || _pin[1] == NULL || _pin[2] == NULL) {
        throw PinError("One or severals pins are not linked.");
    }
    _value.at(0) = _pin[0]->compute(_link[0]);
    _value.at(1) = _pin[1]->compute(_link[1]);
    _value.at(2) = _pin[2]->compute(_link[2]);
    if (_value.at(0) == nts::TRUE) {
        if (_value.at(1) == nts::TRUE) {
            if (_value.at(2) == nts::TRUE) {
                _value.at(3) = nts::TRUE;
                _value.at(4) = nts::TRUE;
            }
            else {
                _value.at(3) = nts::FALSE;
                _value.at(4) = nts::TRUE;
            }
        }
        else {
            if (_value.at(2) == nts::TRUE) {
                _value.at(3) = nts::FALSE;
                _value.at(4) = nts::TRUE;    
            }
            else {
                _value.at(3) = nts::TRUE;
                _value.at(4) = nts::FALSE;
            }
        }
    }  
    else {
        if (_value.at(1) == nts::TRUE) {
            if (_value.at(2) == nts::TRUE) {
                _value.at(3) = nts::FALSE;
                _value.at(4) = nts::TRUE;
            }
            else {
                _value.at(3) = nts::TRUE;
                _value.at(4) = nts::FALSE;
            }
        }
        else {
            if (_value.at(2) == nts::TRUE) {
                _value.at(3) = nts::TRUE;
                _value.at(4) = nts::FALSE;    
            }
            else {
                _value.at(3) = nts::FALSE;
                _value.at(4) = nts::FALSE;
            }
        }
    }
    if (pin == 4)
        return _value.at(3);
    else
        return _value.at(4);
}

void nts::Sum::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if ((pin - 1) > 4) {
        throw PinError("Unknown pin.");
    }
    else if (this->_pin[pin - 1] == NULL) {
        _link[pin - 1] = otherPin;
        this->_pin[pin - 1] = &other;
        other.setLink(otherPin, *this, pin);
    }
}

void nts::Sum::dump() const
{
    std::cout << "Sum" << std::endl;
    for (size_t i = 0; i < 5; i++)
        std::cout << "    pin #" << i << ": " << (((this->_pin[i]) == NULL) ? "NULL" : "linked") << std::endl;
}

nts::Tristate nts::Sum::getValue() const
{
    return nts::UNDEFINED;
}

void nts::Sum::setValue(std::string const &)
{
}