/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:48:01 by pvong             #+#    #+#             */
/*   Updated: 2023/11/08 11:42:56 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point(void) : _x(0), _y(0) {
    // std::cout << GREEN << "Default constructor called" << RESET << std::endl;
    return;
}

Point::~Point(void) {
    // std::cout << RED << "Destructor called" << RESET << std::endl;
    return;
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {
    // std::cout << BOLDGREEN << "Point(" << x << ", " << y << ") constructor called" << RESET << std::endl;
}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {
    // std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
    return;
}

Point &Point::operator=(Point const &rhs) {
    std::cout << BOLDYELLOW << "Copy assignment operator called" << RESET << std::endl;
    (void) rhs;
    return (*this);
}

Fixed const Point::getX(void) {
    return (this->_x);
}

Fixed const Point::getY(void) {
    return (this->_y);
}