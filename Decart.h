#pragma once
#ifndef _DECART_H_
#define _DECART_H_
#include "gtest\gtest_prod.h"
#include <math.h>
#include <cmath>

namespace Prog2 {
	// ����� Decart ���������� �������� ����
	class Decart {
	private:
		double n; // ���������� ����� ��������� �����
	public:
		Decart(double N = 1); // ������ ����������� �� ��������� ���������� �������� ���� � ������������ ������ ������ 1
		// �������
		Decart& setN(double n0);
		// �������
		double getN() const { return n; }
		// ������ ������
		double square_side() const { return n/sqrt(2); } // ������� ��������, ������� ����� ���������� ����� �����
			// ���������� �� ������ � �������� ������� ��������� � ����������� �� ����
		double distance_center(double ang) const { return n*sin(ang)*cos(ang)/(pow(sin(ang),3)+pow(cos(ang),3)); }
		double curvature_vertices() const { return n/(8*sqrt(2)); } // ������ �������� � ������� �����
		double curvature_node() const { return n/2; } // ������ �������� � ������� �����
		double square() const { return n*n/6; } // ������� ����� �����
		double max_diameter() const { return sqrt(4*sqrt(3)-6)/3*n; } // ����� ����������� ����������� �����
		double distance_diameter() const { return n/sqrt(6); } // ���������� �� ���� �� ����������� �����������
		char* frm() const; // ������� ����������� �����
	};
}
#endif