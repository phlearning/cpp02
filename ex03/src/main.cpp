/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:50:23 by pvong             #+#    #+#             */
/*   Updated: 2023/11/08 11:11:43 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

// int main(void) {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));

//     std::cout << "a: " << a << std::endl;
//     std::cout << "++a: " << ++a << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "a++: " << a++ << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "b: " << b << std::endl;
//     std::cout << "Fixed::max(a, b): " << Fixed::max(a, b) << std::endl;
//     return 0;
// }

int main() {
	Point a(1, 1), b(5, 1), c(3, 4), p(3.77f, 2.68f);
	// std::cout << "Enter all the co-ordinates of triangle : ";
	// std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

	// std::cout << "Enter the co-ordinates of point : ";
	// std::cin >> p.x >> p.y;

	bool ans = isInside(a, b, c, p);

	if(ans) {
		std::cout << "The point lies inside the triangle.";
	} else {
		std::cout << "The point lies outside the triangle.";
	}
	std::cout << std::endl;

	return 0;
}
