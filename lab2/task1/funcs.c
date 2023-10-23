#include"enums.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
                return reverse;
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

char* reverse(char * string,int status){
    long int string_len = strlen(string);
    char* answer = malloc(string_len*sizeof(char));
    if (answer == NULL){
        status = 1;
        return answer;
    }
    for (int i = string_len - 1; i > -1; i-- ){
        answer[string_len - i + 1] = string[i];
    }
    return answer;

}