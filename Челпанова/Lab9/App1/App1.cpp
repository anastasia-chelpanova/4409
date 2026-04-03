#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <complex>
#include <functional>
#include <limits>


// Добавляем определение M_PI если оно не определено
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


// Структура для работы с матрицей 3x3
struct Matrix3x3 {
    double m[3][3];

    Matrix3x3() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                m[i][j] = 0.0;
    }

    // Вычисление определителя
    double determinant() const {
        return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
            m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
            m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    }

    // Транспонирование
    Matrix3x3 transpose() const {
        Matrix3x3 res;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                res.m[i][j] = m[j][i];
        return res;
    }

    // Обратная матрица
    Matrix3x3 inverse() const {
        double det = determinant();
        if (std::abs(det) < 1e-9) {
            std::cerr << "Matrix is singular, inverse does not exist." << std::endl;
            return Matrix3x3();
        }

        Matrix3x3 res;
        res.m[0][0] = (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
        res.m[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) / det;
        res.m[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
        res.m[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) / det;
        res.m[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
        res.m[1][2] = (m[0][2] * m[1][0] - m[0][0] * m[1][2]) / det;
        res.m[2][0] = (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;
        res.m[2][1] = (m[0][1] * m[2][0] - m[0][0] * m[2][1]) / det;
        res.m[2][2] = (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;

        return res;
    }

    void print(const std::string& label) const {
        std::cout << label << std::endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << std::setw(10) << std::fixed << std::setprecision(4) << m[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};


// Решение СЛАУ методом Крамера
std::vector<double> solveLinearSystem(const Matrix3x3& A, const std::vector<double>& B) {
    double detA = A.determinant();
    std::vector<double> X(3);

    for (int col = 0; col < 3; ++col) {
        Matrix3x3 Ai = A;
        for (int row = 0; row < 3; ++row) {
            Ai.m[row][col] = B[row];
        }
        X[col] = Ai.determinant() / detA;
    }
    return X;
}

// Решение кубического уравнения (формула Кардано)
std::vector<std::complex<double>> solveCubic(double a, double b, double c) {
    double p = b - a * a / 3.0;
    double q = 2.0 * a * a * a / 27.0 - a * b / 3.0 + c;

    double delta = (q * q / 4.0) + (p * p * p / 27.0);
    std::vector<std::complex<double>> roots;

    if (delta > 0) {
        double u = std::cbrt(-q / 2.0 + std::sqrt(delta));
        double v = std::cbrt(-q / 2.0 - std::sqrt(delta));
        roots.push_back(u + v - a / 3.0);
        std::complex<double> w(-0.5, std::sqrt(3.0) / 2.0);
        roots.push_back(u * w + v / w - a / 3.0);
        roots.push_back(u / w + v * w - a / 3.0);
    }
    else if (std::abs(delta) < 1e-9) {
        double u = std::cbrt(-q / 2.0);
        roots.push_back(2 * u - a / 3.0);
        roots.push_back(-u - a / 3.0);
        roots.push_back(-u - a / 3.0);
    }
    else {
        double r = std::sqrt(-p * p * p / 27.0);
        double theta = std::acos(-q / (2.0 * r));
        double rho = std::cbrt(r);

        roots.push_back(2 * rho * std::cos(theta / 3.0) - a / 3.0);
        roots.push_back(2 * rho * std::cos((theta + 2 * M_PI) / 3.0) - a / 3.0);
        roots.push_back(2 * rho * std::cos((theta + 4 * M_PI) / 3.0) - a / 3.0);
    }
    return roots;
}

// Поиск собственных чисел и векторов
void findEigenValuesVectors(const Matrix3x3& A) {
    double trA = A.m[0][0] + A.m[1][1] + A.m[2][2];

    double m11 = A.m[1][1] * A.m[2][2] - A.m[1][2] * A.m[2][1];
    double m22 = A.m[0][0] * A.m[2][2] - A.m[0][2] * A.m[2][0];
    double m33 = A.m[0][0] * A.m[1][1] - A.m[0][1] * A.m[1][0];
    double sumMinors = m11 + m22 + m33;

    double detA = A.determinant();

    double a = -trA;
    double b = sumMinors;
    double c = -detA;

    std::vector<std::complex<double>> eigenvalues = solveCubic(a, b, c);

    std::cout << "Собственные числа (Eigenvalues):" << std::endl;
    for (size_t i = 0; i < eigenvalues.size(); ++i) {
        std::cout << "lambda" << (i + 1) << " = " << eigenvalues[i] << std::endl;

        if (std::abs(eigenvalues[i].imag()) < 1e-6) {
            double lam = eigenvalues[i].real();
            Matrix3x3 M;
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    M.m[r][c] = A.m[r][c];
                    if (r == c) M.m[r][c] -= lam;
                }
            }
            double vx = M.m[0][1] * M.m[1][2] - M.m[0][2] * M.m[1][1];
            double vy = M.m[0][2] * M.m[1][0] - M.m[0][0] * M.m[1][2];
            double vz = M.m[0][0] * M.m[1][1] - M.m[0][1] * M.m[1][0];

            double norm = std::sqrt(vx * vx + vy * vy + vz * vz);
            if (norm > 1e-9) {
                vx /= norm; vy /= norm; vz /= norm;
                std::cout << "  -> Нормированный собственный вектор: ["
                    << vx << ", " << vy << ", " << vz << "]" << std::endl;
            }
            else {
                vx = M.m[0][1] * M.m[2][2] - M.m[0][2] * M.m[2][1];
                vy = M.m[0][2] * M.m[2][0] - M.m[0][0] * M.m[2][2];
                vz = M.m[0][0] * M.m[2][1] - M.m[0][1] * M.m[2][0];
                norm = std::sqrt(vx * vx + vy * vy + vz * vz);
                if (norm > 1e-9) {
                    vx /= norm; vy /= norm; vz /= norm;
                    std::cout << "  -> Нормированный собственный вектор (alt): ["
                        << vx << ", " << vy << ", " << vz << "]" << std::endl;
                }
            }
        }
    }
    std::cout << std::endl;
}


double f(double x) {
    return x * std::exp(x) - 2;
}

double df(double x) {
    return std::exp(x) * (1 + x);
}

// Метод Ньютона
double solveNewton(double x0, double eps) {
    double x = x0;
    while (std::abs(f(x)) > eps) {
        x = x - f(x) / df(x);
    }
    return x;
}


// Метод Симпсона
double simpson(double a, double b, int n, std::function<double(double)> func) {
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        if (i % 2 == 0) sum += 2 * func(x);
        else sum += 4 * func(x);
    }
    return (h / 3) * sum;
}


void printHistogram(const std::vector<double>& data, double minVal, double maxVal, int bins) {
    std::vector<int> counts(bins, 0);
    double range = maxVal - minVal;
    double binWidth = range / bins;

    for (double val : data) {
        int idx = static_cast<int>((val - minVal) / binWidth);
        if (idx == bins) idx--;
        if (idx >= 0 && idx < bins) counts[idx]++;
    }

    int maxCount = *std::max_element(counts.begin(), counts.end());
    double scale = 50.0 / maxCount;

    std::cout << "\nГистограмма распределения:" << std::endl;
    for (int i = 0; i < bins; ++i) {
        double start = minVal + i * binWidth;
        double end = start + binWidth;
        std::cout << std::setw(8) << std::fixed << std::setprecision(1) << start << " - "
            << std::setw(8) << end << " | ";
        int barLen = static_cast<int>(counts[i] * scale);
        for (int j = 0; j < barLen; ++j) std::cout << "*";
        std::cout << " (" << counts[i] << ")" << std::endl;
    }
}


// Задача 1: Решение системы линейных уравнений
void task1_SolveLinearSystem() {
    std::cout << "=== 1. Решение системы линейных уравнений ===" << std::endl;

    Matrix3x3 A;
    A.m[0][0] = 11; A.m[0][1] = 10; A.m[0][2] = 1;
    A.m[1][0] = 10; A.m[1][1] = -6; A.m[1][2] = 10;
    A.m[2][0] = 2;  A.m[2][1] = -8; A.m[2][2] = -5;

    std::vector<double> B = { 113, 118, -25 };

    A.print("Матрица A:");
    std::cout << "Определитель A: " << A.determinant() << std::endl;

    std::vector<double> X = solveLinearSystem(A, B);
    std::cout << "Решение системы (x, y, z): "
        << X[0] << ", " << X[1] << ", " << X[2] << std::endl << std::endl;
}

// Задача 2: Собственные числа, векторы, A^T, A^-1
void task2_EigenValuesAndMatrices() {
    std::cout << "=== 2. Собственные числа и векторы, A^T, A^-1 ===" << std::endl;

    Matrix3x3 A;
    A.m[0][0] = 11; A.m[0][1] = 10; A.m[0][2] = 1;
    A.m[1][0] = 10; A.m[1][1] = -6; A.m[1][2] = 10;
    A.m[2][0] = 2;  A.m[2][1] = -8; A.m[2][2] = -5;

    findEigenValuesVectors(A);
    A.transpose().print("Матрица A^T:");
    A.inverse().print("Матрица A^-1:");
}

// Задача 3: Решение нелинейного уравнения и построение графика
void task3_NonlinearEquation() {
    std::cout << "=== 3. Решение нелинейного уравнения f(x) = 0 ===" << std::endl;

    double root = solveNewton(1.0, 1e-5);
    std::cout << "Приближенный корень x: " << root << std::endl;
    std::cout << "f(x) в корне: " << f(root) << std::endl;

    std::cout << "g(x) = f'(x) = e^x * (1 + x)" << std::endl;

    std::cout << "\nТаблица значений для построения графика (x, f(x), g(x)):" << std::endl;
    std::cout << std::setw(10) << "x" << std::setw(15) << "f(x)" << std::setw(15) << "g(x)" << std::endl;
    for (double x = -1.0; x <= 2.0; x += 0.5) {
        std::cout << std::setw(10) << x << std::setw(15) << f(x) << std::setw(15) << df(x) << std::endl;
    }
    std::cout << std::endl;
}

// Задача 4: Вычисление интегралов
void task4_Integrals() {
    std::cout << "=== 4. Интегралы ===" << std::endl;

    std::cout << "Точное значение неопределенного интеграла I1:" << std::endl;
    std::cout << "I1 = 0.25 * exp(2 * x^2) + C" << std::endl << std::endl;

    auto integrand = [](double x) { return std::pow(std::asin(x), 4); };
    double I2 = simpson(0.0, 1.0, 1000, integrand);
    std::cout << "Значение определенного интеграла I2 (численно): " << I2 << std::endl << std::endl;
}

// Задача 5: Статистический анализ
void task5_Statistics() {
    std::cout << "=== 5. Статистика (A=-120, B=20) ===" << std::endl;

    const int N = 100;
    const double A_val = -120.0;
    const double B_val = 20.0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(A_val, B_val);

    std::vector<double> sample(N);
    double sum = 0.0;
    double sumSq = 0.0;
    double minEl = std::numeric_limits<double>::max();
    double maxEl = std::numeric_limits<double>::lowest();

    for (int i = 0; i < N; ++i) {
        sample[i] = dist(gen);
        sum += sample[i];
        sumSq += sample[i] * sample[i];
        if (sample[i] < minEl) minEl = sample[i];
        if (sample[i] > maxEl) maxEl = sample[i];
    }

    double mean = sum / N;
    double rms = std::sqrt(sumSq / N);

    std::cout << "Минимальный элемент: " << minEl << std::endl;
    std::cout << "Максимальный элемент: " << maxEl << std::endl;
    std::cout << "Среднее арифметическое: " << mean << std::endl;
    std::cout << "Среднее квадратичное: " << rms << std::endl;

    printHistogram(sample, A_val, B_val, 10);
}


int main() {
    // Устанавливаем локаль для корректного вывода чисел
    std::cout.imbue(std::locale("C"));

    // Последовательный вызов всех задач
    task1_SolveLinearSystem();
    task2_EigenValuesAndMatrices();
    task3_NonlinearEquation();
    task4_Integrals();
    task5_Statistics();

    return 0;
}