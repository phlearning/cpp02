/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:25:21 by pvong             #+#    #+#             */
/*   Updated: 2023/11/06 18:25:04 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

/* ----------------------------- CANONICAL FORM ----------------------------- */

// Default constructor
Fixed::Fixed(void) : _value(0) {
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
    return;
}

// My int constructor
Fixed::Fixed(int const value) {
    std::cout << BOLDGREEN << "Int constructor called" << RESET << std::endl;
    this->_value = value << this->_fractionalBits;
}

// My float constructor
Fixed::Fixed(float const value) {
    std::cout << BOLDGREEN << "Float constructor called" << RESET << std::endl;
    this->_value = (int)(roundf(value * (1 << this->_fractionalBits)));
}

// Copy constructor
Fixed::Fixed(Fixed const &src) : _value(src._value) {
    std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
    return;
}

// Copy Assignement Operator
Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << BOLDYELLOW << "Copy assignment operator called" << RESET << std::endl;
    this->_value = rhs._value;
    return *this;
}

// Destructor
Fixed::~Fixed(void) {
    std::cout << RED << "Destructor called" << RESET << std::endl;
    return;
}

/* -------------------------------------------------------------------------- */


/* -------------------------------- OPERATORS ------------------------------- */


// Comparison operators

bool Fixed::operator>(Fixed const &rhs) {
    return (this->_value > rhs._value);
}

bool Fixed::operator<(Fixed const &rhs) {
    return (this->_value < rhs._value);
}

bool Fixed::operator>=(Fixed const &rhs) {
    return (this->_value >= rhs._value);
}

bool Fixed::operator<=(Fixed const &rhs) {
    return (this->_value <= rhs._value);
}

bool Fixed::operator==(Fixed const &rhs) {
    return (this->_value == rhs._value);
}

bool Fixed::operator!=(Fixed const &rhs) {
    return (this->_value != rhs._value);
}


// Arithmetic operators

Fixed::operator+(Fixed const &rhs) {
    return (Fixed(this->_value + rhs._value));
}

Fixed::operator-(Fixed const &rhs) {
    return (Fixed(this->_value - rhs._value));
}

Fixed::operator*(Fixed const *rhs) {
    return (Fixed(this->_value * rhs._value));
}

Fixed::operator/(Fixed const &rhs) {
    return (Fixed(this->_value / rhs._value));
}

// Increment / Decrement operators

/**
 * This is the pre-increment
 * @return Fixed::Fixed& 
 */
Fixed::Fixed &operator++(void) {
    ++(this->_value);
    return (*this);
} 

/**
 * This is the post-increment
 * @return Fixed::Fixed 
 */
Fixed::Fixed operator++(int) {
    Fixed tmp = *this;
    ++(this->_value);
    return (tmp);
}

/**
 * This is the pre-decrement
 * @return Fixed::Fixed& 
 */
Fixed::Fixed &operator--(void) {
    --(this->_value);
    return (*this);
} 

/**
 * This is the post-decrement
 * @return Fixed::Fixed 
 */
Fixed::Fixed operator--(int) {
    Fixed tmp = *this;
    --(this->_value);
    return (tmp);
}


/* -------------------------------------------------------------------------- */


/* ---------------------------- MEMBER FUNCTIONS ---------------------------- */

int Fixed::getRawBits(void) const {
    std::cout << CYAN << __func__ << RESET << " member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {

    std::cout << __func__ << " member function called" << std::endl;
    this->_value = raw;
    return;
}

float Fixed::toFloat(void) const {
    return (float)(this->_value) / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return (this->_value >> this->_fractionalBits);
}

/* -------------------------------------------------------------------------- */

int const Fixed::_fractionalBits = 8;

std::ostream &operator<<(std::ostream &o, Fixed const &fixed) {
    o << fixed.toFloat();
    return o;
}
