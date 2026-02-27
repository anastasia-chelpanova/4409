#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

// Функции ввода данных
void vvod_klav(double arr[], int &n); // ввод с клавиатуры
void vvod_rand(double arr[], int &n, double &Xmin, double &Xmax); // случайная генерация

// Функции вычисления средних величин
double sred_arifm(double arr[], int n); // среднее арифметическое
double sred_geom(double arr[], int n); // среднее геометрическое
double sred_garm(double arr[], int n); // среднее гармоническое
double sred_kvadr(double arr[], int n); // среднее квадратичное

// Функции анализа
int poisk_max(double arr[], int n); // поиск номера максимума
int poisk_min(double arr[], int n); // поиск номера минимума
int bolshe_srednego(double arr[], int n, double S1); // подсчет элементов > S1

// Функция вывода результатов
void vyvod(double arr[], int n, double S1, double S2, double S3, double S4,int max_i, int min_i, int count);

#endif
