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
	void output_with(const char* msg, Matrix*& matrix); // Вывод матрицы с нулями
	void output_without(const char* msg, Matrix*& matrix); // Вывод матрицы без нулей
	int erase(Matrix*& matrix, int lines); // Освобождение выделенной памяти
	int swap(Matrix*& matrix, int x, int y); // Замена строк
	int task(Matrix*& matrix); // Выполнение задания
	Matrix* copy(Matrix*& matrix); // Копирование матрицы
}

#endif
