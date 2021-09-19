#include <iostream>
#include "matrix.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace Lab1;

int main() {
    Matrix *matrix = input();
    int i = 1;
    if (!matrix) {
        std::cout << "incorrect data" << std::endl;
        return 1;
    }
    std::cout << "\nselect matrix format:\n1) with 0\n2) without 0\n";
    if (getNum(i) < 0) {
        return 1;
    }
    if (i == 1) output_with("\nSourced matrix", matrix);
    else output_without("\nSourced matrix", matrix);
    Matrix* res = copy(matrix);
    if (!res) {
        return 1;
    }
    task(res);
    if (i == 1) output_with("\nResult matrix", res);
    else output_without("\nResult matrix", res);
    erase(matrix, matrix->m); // освобождение памяти
    erase(res, res->m);
    _CrtDumpMemoryLeaks();
    return 0;
}
