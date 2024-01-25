#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include"enums.h"

long double e_limit(long double epsilon){
    long double value = 1.0;
    int n = 1;
    while(value > epsilon){
        value = 1.0/n;
        n++; 
    }
    value = powl((1 + value),n);
    return value;

}


long double e_summ(long double epsilon){
    long double  n = 2.0;
    long double first_val = 1.0;
    long double second_val = 0;
    long double value = first_val * 2;
    while(fabs(first_val - second_val) > epsilon){
        second_val = first_val*1/n;       
        value += second_val;
        first_val = second_val;
        second_val = 0;
        n++;
    }
    return value;

}

long double e_func(long double epsilon){
    long double eps = 0.5;
    while(eps > 0){
        eps = eps * 0.2;
    }
    long double line_left = 2.0;
    long double line_right = 3.0;
    long double middle = 0;
    while(fabs((line_right - line_left)) > epsilon){
        middle = (line_left + line_right) * 0.5;
        if (logl(middle) > 1.0 ){
            line_right = middle;
        }
        else{
            line_left = middle;
        }
    }
    return middle;
}

