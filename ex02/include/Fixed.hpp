/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:25:15 by pvong             #+#    #+#             */
/*   Updated: 2023/11/06 18:18:48 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

class Fixed {

private:
    int _value;
    static int const _fractionalBits;

public:
    // Canonical Form
    Fixed(void);
    Fixed(int const value);
    Fixed(float const value);
    Fixed(Fixed const &src);
    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);

    // Comparison operators
    bool operator>(Fixed const &rhs);
    bool operator<(Fixed const &rhs);
    bool operator>=(Fixed const &rhs);
    bool operator<=(Fixed const &rhs);
    bool operator==(Fixed const &rhs);
    bool operator!=(Fixed const &rhs);

    // Arithmetic operators
    Fixed &operator+(Fixed const &rhs);
    Fixed &operator-(Fixed const &rhs);
    Fixed &operator*(Fixed const &rhs);
    Fixed &operator/(Fixed const &rhs);

    // Increment / Decrement operators
    Fixed &operator++(void); // Pre-increment operator
    Fixed operator++(int); // Post-increment operator
    Fixed &operator--(void); // Pre-increment operator
    Fixed operator--(int); // Post-increment operator

    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif