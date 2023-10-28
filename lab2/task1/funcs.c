#include"enums.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<time.h>


bool is_num(int num){
    if ((num > 47) && (num < 58)){
        return true;
    }
    return false;
}


enum flags command_rec(int argc,char** argv) {
	char* string = argv[1];
    if ((argc > 3) && (string[1] != 'c')){
		return more_than_needs;
	}
	 if (argc < 3){
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
            else{
                return wrong_flag;
            }
            
        }
        else{
            return wrong_flag;
        }
    }
    
}


void reverse(char * string,int* status){
    long int string_len = strlen(string);
    char* answer = (char*)malloc(string_len*sizeof(char));
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
    char* symbs = (char*)malloc(sizeof(char)*string_len);
    int index_counter_nums = 0;
    int index_counter_symbs = 0;
    if (symbs == NULL){
        *status = 1;
        return;
    }
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
    
    free(symbs);
    return;
    
}
bool number_in_array(int* num_array,int array_size, int num2){
    for(int i = 0; i < array_size;i++){
        if (num_array[i] == num2){
            return true;
        }
    }
    return false;
}
int* concatenation_str(char** argv,int* argc,int* status,unsigned int string_quantity){
    unsigned int* indexes = (int*)calloc(string_quantity,sizeof(unsigned int));
    unsigned int last_string_index =  string_quantity-1;
    unsigned int index_count = 0;
    srand(time(NULL));
    int r = rand() % string_quantity + 1;
    if ((indexes == NULL) || (*argc != string_quantity+3)){
        *status = 1;
        return indexes;
    }
    while(indexes[last_string_index] == 0){
        r = rand() % (string_quantity) + 1;
        if (!number_in_array(indexes,string_quantity,r)){
            indexes[index_count] = r;
            index_count++;
        }
    }
    return indexes;

}