/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:51:35 by pvong             #+#    #+#             */
/*   Updated: 2023/11/07 15:24:00 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// https://cppsecrets.com/users/166319711511599105105995564103109971051084699111109/C00-Check-if-given-point-lies-inside-triangle.php

float area(Point a, Point b, Point c) {
    float res = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2.0

    return (res >= 0) ? res : -res;
}

bool isInside(Point a, Point b, point c, point p) {
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