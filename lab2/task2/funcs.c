#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>
#include<math.h>

double average_geom_value(int n, ...){
    double answer = 1;
    va_list factor;
    va_start(factor,n);
    for (int i = 0; i < n; i++){
        answer *= va_arg(factor,int);       
    }
    va_end(factor);
    answer = sqrt(answer);
    return answer;
}


double fast_pow(double d_num, int n){
    double buff;
    if (n == 0){
        return 1;
    }
    else if (n == 1){
        return d_num;
    }
    else if (n % 2 == 0){
        double buff = fast_pow(d_num,n/2);
        buff *= buff;
    }
    else {
        double buff = fast_pow(d_num,n-1);
        buff *= d_num;
    }
    if (d_num <  0){
        buff = 1.0/buff;
        return buff;
    }
    return buff;
}