#include<stdio.h>
#include<math.h>
#include"enums.h"

double calculateSeries1(double x, double epsilon) {
    double result = 1.0;

    double term = 1.0;
    int n = 1;

    while (fabs(term) > epsilon) {
        term *= x / n;
        if (isnan(term)) {
            return result;
        }

        if (isinf(term)) {
            return result;
        }
        result += term;
        n++;
    }

    return result;
}
double calculateSeries2(double x, double epsilon) {
    double result = 1.0;  // Начальное значение, n=0

    double term = 1.0;
    int n = 1;

    while (fabs(term) > epsilon) {
        term *= -1.0 * x * x / (2 * n * (2 * n - 1));
        if (isnan(term)) {
            return result;
        }

        if (isinf(term)) {
            return result;}

        }
        result += term;
        n++;


    return result;
}
unsigned long long my_factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * my_factorial(n - 1);
}

double calculateSeries3(double x, double epsilon) {
    double result = 1.0;

    double term = 1.0;
    int n = 1;

    while (fabs(term) > epsilon) {
        unsigned long long n_factorial = my_factorial(n);
        unsigned long long n_3_factorial = my_factorial(3 * n);

        term *= 3 * 3 * 3 * (double)n_factorial * n_factorial * n_factorial * x * x / (double)n_3_factorial;
        if (isnan(term)) {
            return result;
        }

        if (isinf(term)) {
            return result;

        }
        result += term;
        n++;
    }

    return result;
}
unsigned long long doubleFactorial(int n) {
    if (n <= 0) return 1;
    unsigned long long result = 1;
    for (int i = n; i >= 1; i -= 2) {
        result *= i;
    }
    return result;
}
// функци улетает в бесконечность при epsilon = 0.001
double calculateSeries4(double x, double epsilon) {
//    double result = 0.0;
//
//    double term = 1.0;
//    int n = 0;
//
//    while (fabs(term) > epsilon) {
//        unsigned long long numerator = doubleFactorial(2 * n - 1);
//        unsigned long long denominator = doubleFactorial(2 * n);
//        term = (-1.0) * numerator * x * x / denominator;
//        result += term;
//        n++;
//    }
//
//    return result;
    double result = 0.0;
    int n = 0;

    while (1) {
//        printf("nigga\n");
        unsigned long long numerator = pow(-1, n) * doubleFactorial(2 * n - 1) * pow(x, 2 * n);
        unsigned long long denominator = doubleFactorial(2 * n);

        double term = (double)numerator / denominator;

        if (isnan(term)) {
            return result;
        }

        if (isinf(term)) {
            return result;

        }
        result += term;

        ++n;

        // Проверка на достижение заданной точности
        if (fabs(term) < epsilon) {
            break;
        }
    }

    return result;
}


