#include"enums.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>




bool is_num(int num){
    if ((num > 47) && (num < 58)){
        return true;
    }
    return false;
}


enum flags command_rec(int argc,char** argv) {
	char* string = argv[1];
    if (argc > 3){
		return more_than_needs;
	}
	else if (argc < 3){
		return less_than_needs;
    }
    else{
        if (string[0] == '-'){
            if (string[1] == 'l') {
                return len;
            }
            else if (string[1] == 'r') {
                return reverse_str;
            }
            else if (string[1] == 'u') {
                return odd_up;
            }
            else if (string[1] == 'n') {
                return num_symb;
            }
            else if (string[1] == 'c') {
                return concatenation;
            }
            
        }
    }
    
}


void reverse(char * string,int* status){
    long int string_len = strlen(string);
    char* answer = malloc(string_len*sizeof(char));
    if (answer == NULL){
        *status = 1;
        return;
    }
    for (int i = string_len - 1; i > -1; i-- ){
        answer[string_len-i-1] = string[i];
    }
    strcpy(string,answer);
    free(answer);
    answer = NULL;
    return;


}
void odd_up_str(char* string,int* status){
    long int string_len = strlen(string);
    for (int i = 0; i < string_len; i++){
        if (i % 2 != 0){
            string[i] = toupper(string[i]);
        }
    }
    return;
}

void numb_symb_str(char* string, int* status){
    long int string_len = strlen(string);
    char* symbs = malloc(sizeof(char)*string_len);
    if (symbs == NULL){
        *status = 1;
        return;
    }
    int index_counter_nums = 0;
    int index_counter_symbs = 0;
    for (int i = 0; i < string_len; i++ ){
        if (is_num(string[i])){
            string[index_counter_nums] = string[i];
            index_counter_nums++;
        }
        else{
            symbs[index_counter_symbs] = string[i];
            index_counter_symbs++;
        }
    }
    for (int i = 0; i < index_counter_symbs; i++){
        string[index_counter_nums] = symbs[i];
        index_counter_nums++;
    }  
    

    return;
    
}
void concatenation_str(char** argv,int* status){
    int string_quantity = strtol(argv[2]);


}