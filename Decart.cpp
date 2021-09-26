#include "pch.h"
#include <strstream>
#include <stdio.h>
#include <string.h>
#include "Decart.h"

namespace Prog2 {
	Decart::Decart(double N) { // ������ �����������
		n = N;
	}
	// �������
	Decart& Decart::setN(double n0) {
		n = n0;
		return *this;
	}
	char* Decart::frm() const { // ������� ����������� ����� x^3 + y^3 = nxy
		// ���������� ������ ���������� ������: ����� ���� ����������� ����� � ��������� �������� ���������� n
		char* s1 = "x^3 + y^3 = xy\n"; // ����������� �����
		int l = strlen(s1) + 1; // ��������� ��� ���� �����
		size_t Size = 20;
		char num[20]; // ������ ��� ����� � ��������� ����
		sprintf_s(num, Size, "%.2f", n); // ������������� n � ��������� �������
		l += strlen(num);
		char* s = new char[l];
		sprintf_s(s, l, "x^3 + y^3 = ");
		int k = strlen(s);
		sprintf_s(s + k, l -k, "%.2fxy\n", n);
		return s;
	}
}