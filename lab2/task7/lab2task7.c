#include<stdio.h>
#include<stdlib.h>
#include"funcs.c"
double equation(int x){
     double answer = 2.0*x+12;
     return answer;

}

double find_root(int left_border, int right_border, double eps,double (*equation_ptr)(int),double* status){
    double result  = equation_ptr(3);
    double answer = 0;
    if ((left_border > result) || (right_border < result)){
        *status = 1;
        return answer;
    }
    else if (eps < 0){
        *status = 2;
        return answer;
    }
    while(abs(result - answer) > eps){       
        answer =  (right_border+left_border)/2;
        if (answer > result){
            right_border = answer;
        }
        else{
            left_border = answer;
        }
         printf("result %lf  answer   %lf\n",result, answer);
    }
}

int main(){
    double status = 0;
    find_root(2,50,-12.0001,&equation,&status);
    switch (find_root_debug(status))
    {
        case not_in_range:
            printf("The value is not in range\n");
            break;
        case negative_eps:
            printf("Epsilon should be positive\n");
            break;
        
    }
    return 0;
}