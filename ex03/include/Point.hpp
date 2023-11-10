/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:09:54 by pvong             #+#    #+#             */
/*   Updated: 2023/11/10 13:33:59 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

#define MSG_SEP "===================="

class Point {

private: 
    Fixed const _x;
    Fixed const _y;

    Point &operator=(Point const &rhs);

public:

    Point(void);
    Point(Fixed const x, Fixed const y);
    Point(Point const &src);
    ~Point(void);


    // Member functions
    Fixed const getX(void);
    Fixed const getY(void);
};

float area(Point a, Point b, Point c);
bool bsp(Point const a, Point const b, Point const c, Point const p);
void handleCtrlD(void);
void setPoints(std::string pointName, float *x, float *y);

#endif