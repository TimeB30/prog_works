#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"enums.h"




unsigned long long int fctrl( unsigned int value){

	if (value > 20){
		return 0;
	}
	if (value == 1){
		return 1;
	}
	return value * fctrl(value-1);
    
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
long long int* char_to_int(char** value) {
	long long int* answer = calloc(2,sizeof(long long int));
	char* string = value[2];
	// int answer = 0;
	bool negative = false;
	int i = 0;
	int coefficient = strlen(string)- 1;
	if (string[0] == '-') {
		negative = true;
		i = 1;
		
	}
	for (i; i < strlen(string); i++) {
		if (((string[i] < 48) || (string[i] > 57))) {
			answer[1] = 1;
			return answer;	
		}
		else {
			int num = string[i] - 48;
			answer[0] += num * plow(10, coefficient - i);
		}
	 }
	if (negative) {
		answer[0] *= -1;
	}
	return answer;
}

enum flags command_rec(int argc,char** argv) {
    if (argc > 3){
		return more_than_needs;
	}
	else if (argc < 3){
		return less_than_needs;
	} 
    else if (char_to_int(argv)[1] == 1){
        return not_number;
    }
	if ((!strcmp(argv[1], "-h")) || (!strcmp(argv[1], "/h"))) {
		return multiplicity;
	}
	else if ((!strcmp(argv[1], "-p")) || (!strcmp(argv[1], "/p"))) {
		return simp_comp_check;
	}
	else if ((!strcmp(argv[1], "-s")) || (!strcmp(argv[1], "/s"))) {
		return separate;
	}
	else if ((!strcmp(argv[1], "-e")) || (!strcmp(argv[1], "/e"))) {
		return degree_table;
	}
	else if ((!strcmp(argv[1], "-a")) || (!strcmp(argv[1], "/a"))) {
		return summ_numbers;
	}
	else if ((!strcmp(argv[1], "-f")) || (!strcmp(argv[1], "/f"))) {
		return factorial;
	}
    else {
		return wrong_flag;
	} 
}

int* narutal_multiplicities(int num){
	int* answer = calloc(122,sizeof(int));
	int index =  0;
	for (int i = 0; i < 101; i++){
		if (i % num == 0){
			answer[index] = i;
			index += 1;
		}
	}
	answer[index] = -5;
	return answer;
}
int check_to_simple(int num){
    if (num < 2){
        return 3;
    }
    else if (num == 2){	
        return 1;
    }
	int count = 0;
	for (int i = 1; i <= (int)(num/2); i++){
		if (num % i == 0){
			count += 1;
           
		}
	}
   
	if (count == 1){
		return 1;
	}
	else{
		return 0;
	}
}
