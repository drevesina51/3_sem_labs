#include "pch.h"
#include "tchar.h"
#include <iostream>
#include "..\lab2\Decart.h"

int _tmain(int argc, _TCHAR* argv[]) {
	Prog2::Decart d(1);
	int fl1 = 1;
	double n;
	char* s = NULL;
	while (fl1) {
		std::cout << "Your decart list is:" << std::endl;
		s = d.frm();
		std::cout << s << std::endl;
		delete[] s;
		std::cout << "side of a square that is equal to the largest chord of leaf: " << d.square_side() << std::endl;
		std::cout << "radius of curvature at the top of the sheet: " << d.curvature_vertices() << std::endl;
		std::cout << "radius of curvature at the nodal point: " << d.curvature_node() << std::endl;
		std::cout << "leaf loop area : " << d.square() << std::endl;
		std::cout << "length of the largest cross - section of the loop : " << d.max_diameter() << std::endl;
		std::cout << "distance from the node to the largest cross - section: " << d.distance_diameter() << std::endl;
		int fl2 = 1;
		while (fl2) {
			std::cout << "Enter angle for calculate distance to center in polar coordinate or precc ctrl+Z to quit:" << std::endl;
			double ang;
			std::cin >> ang;
			if (!std::cin.good()) {
				fl2 = 0;
			}
			else
				std::cout << d.distance_center(ang) << std::endl;
		}
		std::cin.clear();
		std::cout << "Enter new n to continue or press ctrl+Z to quit:" << std::endl;
		std::cin >> n;
		if (std::cin.good()) {
			d.setN(n);
		}
		else
			fl1 = 0;
	}
	return 0;
}
