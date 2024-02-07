#include<stdio.h>
#include<math.h>

double integrand1(long double x) {
    if (x == 0){
        return 0.0;
    }
    return log(1 + x) / x;
}


double integrate1(double a, double b, double epsilon) {
    int n = 1;

    double result_previous = 0.0;
    double result_current = 0.0;
    double h = 0;
    do {
        n *= 2;
        h = (b - a) / n;
        if (isnan(result_current)) {
            return result_previous;
        }
        if (isinf(result_current)) {
            return result_previous;

        }
        result_previous = result_current;

        result_current = 0.5 * (integrand1(a) + integrand1(b));

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            result_current += integrand1(x);
        }

        result_current *= h;

    } while (fabsl(result_current - result_previous) > epsilon);

    return result_current;
}


double integrand2(double x) {
    return exp(-0.5 * x * x);
}



double integrate2(double a, double b, double epsilon) {
    int n = 1;

    double h, result_current, result_previous = 0.0;

    do {
        n *= 2;
        h = (b - a) / n;
        if (isnan(result_current)) {
            return result_previous;
        }
        if (isinf(result_current)) {
            return result_previous;

        }
        result_previous = result_current;
        result_current = 0.5 * (integrand2(a) + integrand2(b));

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            result_current += integrand2(x);
        }

        result_current *= h;

    } while (fabs(result_current - result_previous) > epsilon);

    return result_current;
}


double integrand3(double x) {
    if (x == 1){
        x = 0.999;
    }
    return log(1 / (1 - x));
}


double integrate3(double a, double b, double epsilon) {
    int n = 1;

    double h, result_current, result_previous = 0.0;

    do {
        n *= 2;
        h = (b - a) / n;
        if (isnan(result_current)) {
            return result_previous;
        }
        if (isinf(result_current)) {
            return result_previous;

        }
        result_previous = result_current;
        result_current = 0.5 * (integrand3(a) + integrand3(b));

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            result_current += integrand3(x);
        }

        result_current *= h;

    } while (fabs(result_current - result_previous) > epsilon);

    return result_current;

}

double integrand4(double x) {
    return pow(x, x);
}

double integrate4(double a, double b, double epsilon) {
    int n = 1;

    double h, result_current, result_previous = 0.0;

    do {
        n *= 2;
        h = (b - a) / n;
        if (isnan(result_current)) {
            return result_previous;
        }
        if (isinf(result_current)) {
            return result_previous;

        }
        result_previous = result_current;
        result_current = 0.5 * (integrand4(a) + integrand4(b));

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            result_current += integrand4(x);
        }

        result_current *= h;

    } while (fabs(result_current - result_previous) > epsilon);

    return result_current;
}