/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:21:54 by pvong             #+#    #+#             */
/*   Updated: 2023/11/08 11:50:56 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed(void) : _value(0) {
    if (SHOWMSG)
        std::cout << GREEN << "Default constructor called" << RESET << std::endl;
    return;
}

// Copy constructor
Fixed::Fixed(Fixed const &src) : _value(src._value) {
    if (SHOWMSG)
        std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
    return;
}

// Copy Assignement Operator
Fixed &Fixed::operator=(Fixed const &rhs) {
    if (SHOWMSG)
        std::cout << BOLDYELLOW << "Copy assignment operator called" << RESET << std::endl;
    this->_value = rhs._value;
    return *this;
}

// Destructor
Fixed::~Fixed(void) {
    if (SHOWMSG)
        std::cout << RED << "Destructor called" << RESET << std::endl;
    return;
}

int Fixed::getRawBits(void) const {
    std::cout << CYAN << __func__ << RESET << " member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {

    std::cout << __func__ << " member function called" << std::endl;
    this->_value = raw;
    return;
}

int const Fixed::_fractionalBits = 8;
