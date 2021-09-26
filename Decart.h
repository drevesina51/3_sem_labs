#pragma once
#ifndef _DECART_H_
#define _DECART_H_
#include "gtest\gtest_prod.h"
#include <math.h>
#include <cmath>

namespace Prog2 {
	// класс Decart определяет декартов лист
	class Decart {
	private:
		double n; // наибольшая хорда декартого листа
	public:
		Decart(double N = 1); // пустой конструктор по умолчанию определяет декартов лист с максимальной хордой равной 1
		// сеттеры
		Decart& setN(double n0);
		// геттеры
		double getN() const { return n; }
		// другие методы
		double square_side() const { return n/sqrt(2); } // сторона квадрата, которая равна наибольшей хорде листа
			// расстояние до центра в полярной системе координат в зависимости от угла
		double distance_center(double ang) const { return n*sin(ang)*cos(ang)/(pow(sin(ang),3)+pow(cos(ang),3)); }
		double curvature_vertices() const { return n/(8*sqrt(2)); } // радиус кривизны в вершине листа
		double curvature_node() const { return n/2; } // радиус кривизны в узловой точке
		double square() const { return n*n/6; } // площадь петли листа
		double max_diameter() const { return sqrt(4*sqrt(3)-6)/3*n; } // длина наибольшего поперечника петли
		double distance_diameter() const { return n/sqrt(6); } // расстояния от узла до наибольшего поперечника
		char* frm() const; // формула декартового листа
	};
}
#endif