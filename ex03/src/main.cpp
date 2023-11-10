/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:50:23 by pvong             #+#    #+#             */
/*   Updated: 2023/11/10 13:34:12 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

void handleCtrlD(void) {

    if (std::cin.eof()) {
        std::cout << "End of input. Exiting." << std::endl;
        exit(0);
    }
}

void setPoints(std::string pointName, float *x, float *y)
{

	std::cout << BOLDWHITE << pointName << RESET << std::endl;
	std::cout << BOLDBLACK << MSG_SEP << RESET << std::endl;
	std::cout << "Set " << BLUE << pointName << RESET << ".x: ";
	while (!(std::cin >> *x)) {
		handleCtrlD();
		std::cout << RED << "Error: Invalid number" << RESET << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Set " << BLUE << pointName << RESET << ".x: ";
	}
	std::cout << "Set " << BLUE << pointName << RESET << ".y: ";
	while (!(std::cin >> *y)) {
		handleCtrlD();
		std::cout << RED << "Error: Invalid number" << RESET << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Set " << BLUE << pointName << RESET << ".y: ";
	}
	std::cout << "Point "<< BOLDWHITE << pointName << CYAN << "(" << *x << ", " << *y << ")" << RESET << " has been set" << std::endl;
	std::cout << BOLDBLACK << MSG_SEP << RESET << std::endl;
	std::cout << std::endl;
}

int main() {

	float x1, y1, x2, y2, x3, y3, x4, y4;

	setPoints("A", &x1, &y1);
	setPoints("B", &x2, &y2);
	setPoints("C", &x3, &y3);
	setPoints("D", &x4, &y4);
	Point a(x1, y1), b(x2, y2), c(x3, y3), p(x4, y4);

	// Point a(1, 1), b(2, 4), c(3, 1), p(3.57f, 2.86f);
	// Point a(1, 1), b(2, 4), c(3, 1), p(2.29f, 2.34f);

	bool ans = bsp(a, b, c, p);

	if(ans) {
		std::cout << GREEN << "Result: " << RESET << "The point lies inside the triangle.";
	} else {
		std::cout << GREEN << "Result: " << RESET << "The point lies outside the triangle.";
	}
	std::cout << std::endl;

	return 0;
}
