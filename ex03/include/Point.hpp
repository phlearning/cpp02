/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:09:54 by pvong             #+#    #+#             */
/*   Updated: 2023/11/07 16:17:52 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

private: 
    Fixed const _x;
    Fixed const _y;

public:
    // Canonical form
    Point(void);
    Point(Fixed const x, Fixed const y);
    Point(Point const &src);
    ~Point(void);

    Point &operator=(Point const &rhs);

    // Member functions
    float getX(void);
    float getY(void);
};

float area(Point a, Point b, Point c);
bool isInside(Point a, Point b, Point c, Point p);

#endif