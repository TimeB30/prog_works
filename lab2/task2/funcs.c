#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>
#include<math.h>

double average_geom_value(int* status,int n, ...){
    double answer = 1;
    va_list factor;
    va_start(factor,n);
    for (int i = 0; i < n; i++){
        answer *= va_arg(factor,int);  
    }
    va_end(factor);
    if ((n < 0) || (answer < 0)){
        *status = 1;
        return answer;
    }
    answer = pow(answer,1.0/n);
    return answer;
}


double fast_pow(double d_num, int n){
    double buff;
    int n2 = abs(n);
    if (n2 == 1){
        return d_num;
    }
    else if (n2 == 0){
        return 1.0;
    }
    else if (n2 % 2 == 0){
        buff = fast_pow(d_num,n2/2);
        buff *= buff;
    }
    else {
        buff = fast_pow(d_num,n2-1);
        buff *= d_num;
    }
    if (n <  0){
        buff = 1.0/buff;
        return buff;
    }
    return buff;

}