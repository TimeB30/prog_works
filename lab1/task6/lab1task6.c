#include"func.c"
#include<stdlib.h>
#include<float.h>
int main(int argc, char** argv){
    if (argc != 2){
        printf("Wrong quantity of arguments\n");
        return 0;
    }
    double a = 0.0;
    double b = 1.0;
    char* end  = end;
    double machine_epsilon = DBL_EPSILON;
    double epsilon = strtod(argv[1],&end);
    if (end == argv[1]){
        printf("wrong argument\n");
        return 0;
    }
    if (epsilon > machine_epsilon){
        double result1 = integrate1(a,b, epsilon);
        double result2 = integrate2(a,b, epsilon);
        double result3 = integrate3(a,b, epsilon);
        double result4 = integrate4(a,b, epsilon);

        printf("a: %f\n",result1);
        printf("b: %f\n",result2);
        printf("c: %f\n",result3);
        printf("d: %f\n",result4);
    }
    else{
        printf("Too small epsilon 0\n");
        return 0;
    }


    return 0;
}