#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include"enums.h"
enum flags situaition(double* result){
    if #cont flags
}
long long int plow(int num, int degr) {
	if (degr == 0){
		return 1;
	}
	long long int answer = num;
	for (int i = 0; i < degr-1; i++) {
		answer *= num;
	}
	return answer;
}

long double* char_to_double(char* argv[]){
    long double* answer = calloc(2,sizeof(long double));
    char* string = argv[1];
    bool dot_detector = false;
    int coefficient = 0;
    for (int i = 0; i < strlen(string); i++){
        if (string[i] == '.'){
            coefficient = i-1;
            break;
        }
    }
    if (string[0] == '-'){
         answer[1] = 1.0;   
         return answer;
    }
    for (int i = 0; i < strlen(string);i++){
        if (string[i] == '.'){
            if (dot_detector){
                answer[1] = 1.0;
                return answer;
            }
            dot_detector = true;
        }
        else if (dot_detector){
             if (((string[i] < 48) || (string[i] > 57))) {
                answer[1] = 1.0;
                return answer;
            }
            else{
                // printf("hey %lf",(1.0/(1*plow(10,i-coefficient-1))));
                double num = string[i] - 48;
                answer[0] += num/(1*plow(10,i-coefficient-1));
            }
        }
        else{
            if (((string[i] < 48) || (string[i] > 57))) {
                answer[1] = 1.0;
                return answer;
            }
            else {
                double num = string[i] - 48;
                answer[0] += num * plow(10, coefficient - i);
		    }
        }
		

    }
    return answer;
}   