#include "pch.h"
#include <strstream>
#include <stdio.h>
#include <string.h>
#include "Decart.h"

namespace Prog2 {
	Decart::Decart(double N) { // пустой конструктор
		n = N;
	}
	// сеттеры
	Decart& Decart::setN(double n0) {
		n = n0;
		return *this;
	}
	char* Decart::frm() const { // формула декартового листа x^3 + y^3 = nxy
		// определяем размер выделяемой памяти: сумма длин константной части и числового значения переменной n
		char* s1 = "x^3 + y^3 = xy\n"; // константная часть
		int l = strlen(s1) + 1; // добавляем для нуль байта
		size_t Size = 20;
		char num[20]; // помять для числа в текстовом виде
		sprintf_s(num, Size, "%.2f", n); // представление n в текстовом формате
		l += strlen(num);
		char* s = new char[l];
		sprintf_s(s, l, "x^3 + y^3 = ");
		int k = strlen(s);
		sprintf_s(s + k, l -k, "%.2fxy\n", n);
		return s;
	}
}
