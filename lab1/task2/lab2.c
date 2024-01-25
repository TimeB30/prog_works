#include"func.c"

long double find_eps(){
    long double value = 1.0;
    while (value > 0){
        value *= 0.5;
    }
    return value;
}


int main(int argc, char* argv[]){
//    long double machine_eps = find_eps();
    char** end;
    long double epsilon = strtod(argv[1],end);
    if ((epsilon > 0) && (epsilon < 1)){
        printf("the epsilon is %Lf\n", epsilon);
        long double e_limit_result = e_limit(epsilon);
        printf("\n%.20Lf\n", e_limit_result);
        long double e_summ_result = e_summ(epsilon);
        printf("%.20Lf\n", e_summ_result);
        long double e_func_result = e_func(epsilon);
        printf("%.20Lf\n", e_func_result);
    }
    else{
        printf("wrong epsilon, should be more than 0 and less than 1\n");
    }


    
    return 0;
}