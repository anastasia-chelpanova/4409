#include <iostream>      // библ дл€ cin, cout
#include <cmath>         // библ дл€ pow, sqrt
#include <cstdlib>       // библ дл€ rand()
#include <ctime>         // библ дл€ time()
#include "header.h"       // подключение заголовочного файла

// 1. ‘”Ќ ÷»» ¬¬ќƒј ƒјЌЌџ’

// vvod_klav - ввод массива с клавиатуры

void vvod_klav(double arr[], int &n) {  //arr[] - массив, & - передача по ссылке

    // ¬вод количества элементов с проверкой

    std::cout << "Vvedite n (0 < n < 100): ";
    std::cin >> n;

    // ÷икл while - повтор€етс€, пока условие истинно

    while (n <= 0 || n >= 100) {  // || - логическое или
        std::cout << "Oshibka! Vvedite n: ";
        std::cin >> n;
    }

    // ¬вод элементов массива

    std::cout << "Vvedite " << n << " elementov:\n";
    for (int i = 0; i < n; i++) {  // for Ч цикл со счетчиком, который повтор€ет действи€ заданное количество раз.
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
}

// vvod_rand - заполнение массива случайными числами

void vvod_rand(double arr[], int &n, double &Xmin, double &Xmax) {

    // ¬вод количества элементов с проверкой

    std::cout << "Vvedite n (0 < n < 100): ";
    std::cin >> n;

    while (n <= 0 || n >= 100) {
        std::cout << "Oshibka! Vvedite n: ";
        std::cin >> n;
    }

    // ¬вод границ диапазона

    std::cout << "Vvedite Xmin: ";
    std::cin >> Xmin;
    std::cout << "Vvedite Xmax: ";
    std::cin >> Xmax;

    // »нициализаци€ генератора случайных чисел

    std::srand(std::time(NULL)); // Ч инициализаци€ генератора случайных чисел текущим временем.

    // √енераци€ элементов массива

    for (int i = 0; i < n; i++) {
        double r = (double)std::rand() / RAND_MAX;  // Ч получение случайного вещественного числа от 0 до 1
        arr[i] = Xmin + r * (Xmax - Xmin); // Ч преобразование случайного числа r (от 0 до 1) в число из диапазона [Xmin, Xmax]
    }

    // ¬ывод сгенерированного массива

    std::cout << "\nSgenerirovanny massiv:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl; // Ч вывод элемента массива на экран
    }
}

// 2. ‘”Ќ ÷»» ¬џ„»—Ћ≈Ќ»я —–≈ƒЌ»’ ¬≈Ћ»„»Ќ

// sred_arifm - среднее арифметическое

double sred_arifm(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Ч добавить значение элемента массива к переменной sum
    }
    return sum / n; //Ч возврат результата из функции
}

// sred_geom - среднее геометрическое

double sred_geom(double arr[], int n) {
    double prod = 1; // Ч объ€вление переменной дл€ накоплени€ произведени€ с начальным значением 1
    for (int i = 0; i < n; i++) {
        prod *= arr[i]; // Ч умножить переменную prod на текущий элемент массива
    }
    return std::pow(prod, 1.0 / n); // Ч возврат корн€ n-й степени из произведени€ (среднее геометрическое)
}

// sred_garm - среднее гармоническое

double sred_garm(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            sum += 1.0 / arr[i]; // Ч добавление обратной величины элемента к сумме
        }
    }
    return n / sum;
}

// sred_kvadr - среднее квадратичное

double sred_kvadr(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i] * arr[i]; //  Ч добавление квадрата элемента к сумме
    }
    return std::sqrt(sum / n);
}

// 3. ‘”Ќ ÷»» јЌјЋ»«ј

// poisk_max - поиск индекса максимального элемента

int poisk_max(double arr[], int n) {
    int max_i = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_i]) { // Ч проверка, больше ли текущий элемент текущего максимума
            max_i = i;
        }
    }
    return max_i;
}

// poisk_min - поиск индекса минимального элемента

int poisk_min(double arr[], int n) {
    int min_i = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min_i]) {
            min_i = i;
        }
    }
    return min_i;
}

// bolshe_srednego - подсчет элементов > S1

int bolshe_srednego(double arr[], int n, double S1) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > S1) { // -Ч проверка, больше ли текущий элемент среднего арифметического
            count++; // Ч увеличить переменную-счетчик на 1
        }
    }
    return count;
}

// 4. ‘”Ќ ÷»я ¬џ¬ќƒј –≈«”Ћ№“ј“ќ¬

// vyvod - вывод всех результатов

void vyvod(double arr[], int n, double S1, double S2, double S3, double S4, int max_i, int min_i, int count) {

    std::cout << "\n========== REZULTATY ==========\n";

    // ¬ывод исходного массива

    std::cout << "ishodny massiv:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    // ¬ывод средних величин

    std::cout << "\n--- Srednie velichiny ---\n";
    std::cout << "S1 (arifmeticheskoe)  = " << S1 << std::endl;
    std::cout << "S2 (geometricheskoe)   = " << S2 << std::endl;
    std::cout << "S3 (garmonicheskoe)    = " << S3 << std::endl;
    std::cout << "S4 (kvadratichnoe)     = " << S4 << std::endl;

    // ¬ывод результатов анализа

    std::cout << "\n--- Analiz (variant 1) ---\n";
    std::cout << "Nomer maximalnogo elementa: " << max_i;
    std::cout << " (znachenie " << arr[max_i] << ")" << std::endl;
    std::cout << "Nomer minimalnogo elementa: " << min_i;
    std::cout << " (znachenie " << arr[min_i] << ")" << std::endl;
    std::cout << "Kolichestvo elementov > S1: " << count << std::endl;

    std::cout << "================================\n";
}
