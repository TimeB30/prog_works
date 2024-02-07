#include"func.c"
#include<stdlib.h>
#include<float.h>
int main(int argc, char** argv){
    char* end1;
    char* end2;
    if (argc != 3){
        printf("Wrong quantity of arguments\n");
        return 0;
    }
    double x = strtod(argv[1],&end1);
    double epsilon = strtod(argv[2],&end2);
    if (end1 == argv[1]){
        printf("Error: wrong input argument\n");
        return 0;
    }
    double machine_epsilon = DBL_EPSILON;
    if (epsilon > machine_epsilon) {
        if (end2 == argv[2]) {
            printf("Error: wrong input argument\n");
            return 0;
        }
        double result1 = calculateSeries1(x, epsilon);
        printf("Результат для x=%f с точностью %f: %f\n", x, epsilon, result1);

        double result2 = calculateSeries2(x, epsilon);
        printf("Результат для x=%f с точностью %f: %f\n", x, epsilon, result2);

        double result3 = calculateSeries3(x, epsilon);
        printf("Результат для x=%f с точностью %f: %f\n", x, epsilon, result3);

        double result4 = calculateSeries4(x, epsilon);
        printf("Результат для x=%f с точностью %f: %.50f\n", x, epsilon, result4);
    }
    else{
        printf("Слишком маленький epsilon\n");
    }
    return 0;

}