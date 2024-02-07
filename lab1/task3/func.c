#include<stdio.h>
#include"enums.h"
#include<stdlib.h>
#include<math.h>
#include<float.h>
#include<stdarg.h>
//long double* convert(int* status,int num, ...){\
//    char* end;
//    long double* answer = malloc(sizeof(long double)*num);
//    if (answer == NULL){
//        *status = 1;
//        return answer;
//    }
//    va_list args;
//    va_start(args,num);
//    for(int i = 0; i < num; i++){
//        char* str = va_arg(args,char*);
//        long double buff = strtold(str,&end);
//        if (end == str){
//            *status = 2;
//            return answer;
//        }
//        answer[i] = buff;
//    }
//    return answer;
//}
long double getMachineEpsilonLongDouble() {
    return LDBL_EPSILON;
}

void clear_memory(long double** value,int end){
    for (int i = 0; i < end; i++){
        free(value[i]);
    }
}
long double** solveQuadratic(long double a,long double b,long double c,int* status) {
    long double** answer = (long double**)malloc(6*sizeof(long double*));
    if (answer == NULL){
        *status = 1;
        return answer;
    }
    for (int i = 0; i < 6; i++){
        answer[i] = (long double*)malloc(6*sizeof(long double));
        if (answer[i] == NULL) {
            *status = 1;
            return answer;
        }
    }
    long double combination[6][4]= {{a,b,c},
                                    {a,c,b},
                                    {b,c,a},
                                    {b,a,c},
                                    {c,b,a},
                                    {c,a,b}
                            };
    for (int i = 0; i < 6; i++){
        long double a = combination[i][0];
        long double b = combination[i][1];
        long double c = combination[i][2];
        long double discriminant = b * b - 4 * a * c;
        answer[i][0] = a;
        answer[i][1] = b;
        answer[i][2] = c;
        if (discriminant > 0) {
            long double root1 = (-b + sqrtl(discriminant)) / (2 * a);
            long double root2 = (-b - sqrtl(discriminant)) / (2 * a);
            answer[i][3] = 2;
            answer[i][4] = root1;
            answer[i][5] = root2;
            printf("Уравнение имеет два корня: %.2Lf и %.2Lf\n", root1, root2);

        } else if (discriminant == 0) {
            long double root = -b / (2 * a);
            printf("Уравнение имеет один корень: %.2Lf\n", root);
            answer[i][3] = 1;
            answer[i][4] = root;
            answer[i][5] = root;
        } else {
            answer[i][3] = 0;
            answer[i][4] = 0;
            answer[i][5] = 0;
            printf("нет корней\n");
        }
    }
    return answer;

}
//int isMultiple(int a, int b) {
//    return (b != 0 && a % b == 0);
//}
int isMultiple(long double firstNumber, long double secondNumber) {
    long double epsilon  = LDBL_EPSILON;
    if (secondNumber > epsilon) {
        long double result = firstNumber / secondNumber;
        return fabsl(result - round(result)) < epsilon;
    } else {
        return -1;
    }
}

int isRightTriangle(long double a, long double b, long double c, long double epsilon) {
    return fabsl(a * a + b * b - c * c) < epsilon ||
           fabsl(a * a + c * c - b * b) < epsilon ||
           fabsl(b * b + c * c - a * a) < epsilon;
}



enum flags command_rec(int argc,char* argv[]) {
    if (argc < 2){
	return wrong_quantity;
	}
    char flag = argv[1][1];
    if ((argv[1][0] != '/') && (argv[1][0] != '-')) {
        return wrong_input;
    } else if (argc < 3) {
        return wrong_quantity;
    }
    else if (flag == 'q') {
        if (argc != 5){
            return wrong_quantity;
        }
        return quadratic;
    }
    else if (flag == 'm'){
        if (argc != 4){
            return wrong_quantity;
        }
        return multiplicity;
    }
    else if (flag == 't'){
        if (argc != 6){
            return wrong_quantity;
        }
        return triangle;
    }
    else{
        return wrong_input;
    };
}