#include"func.c"




int main(int argc, char* argv[]){
    char** ptr;
    long double epsilon = strtod(argv[1],ptr);
    printf("the epsilon is %Lf\n",epsilon);
    long double e_limit_result = e_limit(epsilon);
    printf("\n%.20Lf\n",e_limit_result);
    long double e_summ_result = e_summ(epsilon);
    printf("%.20Lf\n",e_summ_result);
    long double e_func_result = e_func(epsilon);
    printf("%.20Lf\n",e_func_result);
    
    return 0;
}