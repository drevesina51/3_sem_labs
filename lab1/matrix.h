#pragma once
#ifndef MATRIX_H
#define MATRIX_H

namespace Lab1 {

	struct List {
		double a; // значение
		int pos; // позиция в строке
		List* next;
	};

	struct Matrix {
		int n; // кол-во строк
		int m; // кол-во столбцов
		List* lines;
	};

	template <class T>
	int getNum(T& a) {
		std::cin >> a;
		if (!std::cin.good()) // обнаружена ошибка ввода или конец файла
			return -1;
		return 1;
	}

	Matrix* input(); // Ввод матрицы
	void output(const char* msg, Matrix*& matrix); // Вывод матрицы
	Matrix* erase(Matrix*& matrix, int lines); // Освобождение выделенной памяти
	int swap(Matrix*& matrix, int x, int y); // Замена строк
	int task(Matrix*& matrix); // Выполнение задания
}

#endif
