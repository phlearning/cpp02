/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:51:35 by pvong             #+#    #+#             */
/*   Updated: 2023/11/08 14:20:28 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * Use: Calculate a triangular area
 * 
 * Knowing the coords of the 3 points in a triangle we get this formula: 
 * (1/2) |x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|
 * 
 * Translating to our points we get the following:
 * |(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y))/2.0|
 * @param a 
 * @param b 
 * @param c 
 * @return float 
 */
float area(Point a, Point b, Point c) {
    float res = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) + c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0;

    return (res >= 0) ? res : -res;
}

bool isInside(Point a, Point b, Point c, Point p) {
    const float eps = 0.00001f;
    float a1 = area(a, b, p);
    float a2 = area(a, c, p);
    float a3 = area(b, c, p);
    float big = area(a, b, c);

    float resultArea = big - (a1 + a2 + a3);
    if (resultArea < 0) {
        resultArea = -resultArea;
    }

    return (resultArea < eps);
}