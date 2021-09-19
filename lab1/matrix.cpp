#include <iostream>
#include "matrix.h"

namespace Lab1 {

	int erase(Matrix*& matrix, int lines) {
		List* ptr = nullptr;
		List* tmp = nullptr;
		if (lines != 0) {
			for (int i = 0; i < matrix->m; ++i) {
				ptr = &matrix->lines[i];
				ptr = ptr->next;
				while (ptr != nullptr) {
					tmp = ptr->next;
					delete ptr;
					ptr = tmp;
				}
			}
		}
		delete[] matrix->lines;
		delete matrix;
		return 0;
	}

	Matrix* input() {
		Matrix* matrix = nullptr;
		const char* pr = "You are wrong; repeat please!";
		int n, m;
		double s;
		try {
			matrix = new Matrix;
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "------ failure to allocate memory for the matrix: " << ba.what() << std::endl;
			return nullptr;
		}
		do {
			std::cout << "Enter number of lines m: --> ";
			if (getNum(m) < 0 || m <= 0) {
				std::cout << pr << std::endl;
				return nullptr;
			}
		} while (m < 1);
		matrix->m = m;
		do {
			std::cout << "Enter number of rows n: --> ";
			if (getNum(n) < 0 || n <= 0) {
				std::cout << pr << std::endl;
				return nullptr;
			}
		} while (n < 1);
		matrix->n = n;
		// выделение памяти под массив списков
		try {
			matrix->lines = new List[m];
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "------ too many lines in matrix: " << ba.what() << std::endl;
			erase(matrix, 0);
			return nullptr;
		}
		for (int w = 0; w < m; w++) {
			List* qwe = &matrix->lines[w];
			qwe->next = nullptr;
			qwe->pos = -1;
		}
		// ввод матрицы
		for (int i = 0; i < m; i++) {
			List* ptr = &matrix->lines[i];
			std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
			for (int j = 0; j < n; j++) {
				if (getNum(s) < 0) { // обнаружена ошибка ввода или конец файла
					erase(matrix, i + 1); // освобождение памяти выделенной выше
					return nullptr;
				}
				if (s != 0) {
					ptr->a = s;
					ptr->pos = j;
					try {
						ptr->next = new List;
					}
					catch (std::bad_alloc& ba) {
						std::cout << "------ too many items in matrix: " << ba.what() << std::endl;
						erase(matrix, i + 1);
						return nullptr;
					}
					ptr = ptr->next;
					ptr->next = nullptr;
					ptr->pos = -1;
				}
			}
		}
		return matrix;
	}

	void output_with(const char* msg, Matrix*& matrix) {
		std::cout << msg << ":\n";
		List* ptr = nullptr;
		for (int i = 0; i < matrix->m; ++i) {
			ptr = &matrix->lines[i];
			for (int j = 0; j < matrix->n; ++j) {
				if (ptr->pos == j) {
					std::cout << ptr->a << " ";
					ptr = ptr->next;
				}
				else
					std::cout << 0 << " ";
			}
			std::cout << std::endl;
		}
	}

	void output_without(const char* msg, Matrix*& matrix) {
		std::cout << msg << ":\n";
		List* ptr = nullptr;
		for (int i = 0; i < matrix->m; ++i) {
			ptr = &matrix->lines[i];
			for (int j = 0; j < matrix->n; ++j) {
				if (ptr->pos == j) {
					std::cout << ptr->a << " ";
					ptr = ptr->next;
				}
			}
			std::cout << std::endl;
		}
	}

	Matrix* copy(Matrix*& matrix) {
		Matrix* res = nullptr;
		try {
			res = new Matrix;
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "------ failure to allocate memory for the matrix: " << ba.what() << std::endl;
			return nullptr;
		}
		res->m = matrix->m;
		res->n = matrix->n;
		// выделение памяти под массив списков
		try {
			res->lines = new List[res->m];
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "------ too many lines in matrix: " << ba.what() << std::endl;
			erase(res, 0);
			return nullptr;
		}
		for (int w = 0; w < res->m; w++) {
			List* qwe = &res->lines[w];
			qwe->next = nullptr;
			qwe->pos = -1;
		}
		List* ptr = nullptr;
		List* tmp = nullptr;
		for (int i = 0; i < res->m; ++i) {
			ptr = &matrix->lines[i];
			tmp = &res->lines[i];
			while (ptr != nullptr) {
				tmp->a = ptr->a;
				tmp->pos = ptr->pos;
				try {
					tmp->next = new List;
				}
				catch (std::bad_alloc& ba) {
					std::cout << "------ too many items in matrix: " << ba.what() << std::endl;
					erase(res, i + 1);
					return nullptr;
				}
				tmp = tmp->next;
				tmp->next = nullptr;
				tmp->pos = -1;;
				ptr = ptr->next;
			}
		}
		return res;
	}

	int swap(Matrix*& matrix, int x, int y) {
		List ptr = matrix->lines[y];
		matrix->lines[y] = matrix->lines[x];
		matrix->lines[x] = ptr;
		return 0;
	}

	int task(Matrix*& matrix) {
		int m_pos = 0;
		int m_neg = 0;
		int q = 0;
		int w = 0;
		int x = 0;
		int y = matrix->m - 1;
		List* ptr = nullptr;
		for (int i = 0; i < matrix->m; ++i) {
			ptr = &matrix->lines[i];
			if (ptr->pos != -1) {
				q = 0;
				w = 0;
				while (ptr->pos != -1) {
					if (ptr->a < 0) {
						q++;
					}
					if (ptr->a > 0) {
						w++;
					}
					ptr = ptr->next;
				}
				if (q >= m_neg) {
					m_neg = q;
					y = i;
				}
				if (w > m_neg) {
					m_pos = w;
					x = i;
				}
			}
		}
		swap(matrix, 0, x);
		if (x != y) {
			if (y == 0) {
				swap(matrix, matrix->m - 1, x);
			}
			else swap(matrix, matrix->m - 1, y);
		}
		return 0;
	}
}
