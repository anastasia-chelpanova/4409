#include "Matrix.hpp"
#include <iostream>
#include <iomanip>

int** createMatrix(int n) {
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        // Инициализируем все элементы нулями!
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void fillMatrix(int** matrix, int n) {
    int counter = 1;
    int mid = n / 2;

    // Заполняем только верхнюю часть (треугольник)
    for (int i = 0; i <= mid; ++i) {
        for (int j = i; j < n - i; ++j) {
            matrix[i][j] = counter;
            counter++;
        }
    }
    // Нижняя часть уже заполнена нулями из createMatrix
}

void printMatrix(int** matrix, int n) {
    std::cout << "\nResult (variant 4):\n\n";

    // Находим максимальное число для правильного выравнивания
    int maxNum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] > maxNum) {
                maxNum = matrix[i][j];
            }
        }
    }

    // Вычисляем ширину столбца
    int width = 1;
    int temp = maxNum;
    while (temp >= 10) {
        width++;
        temp /= 10;
    }
    width += 2; // запас для красоты

    // Выводим матрицу
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(width) << matrix[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}