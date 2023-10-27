#include<stdio.h>
#include<stdlib.h>
#include"funcs.c"
double equation(int x){
     double answer = 2.0*x+12;
     return answer;

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