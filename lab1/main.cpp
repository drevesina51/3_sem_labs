#include <iostream>
#include "matrix.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace Lab1;

int main() {
    Matrix *matrix = input();
    if (!matrix) {
        std::cout << "incorrect data" << std::endl;
        return 1;
    }
    output("Sourced matrix", matrix);
    task(matrix);
    output("Result matrix", matrix);
    erase(matrix, matrix->m); // освобождение памяти
    _CrtDumpMemoryLeaks();
    return 0;
}
