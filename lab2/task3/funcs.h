#include<stdlib.h>
#include<stdio.h>
#include"enums.h"
#include<stdarg.h>
#include<string.h>
#include<stdbool.h>
void move_values_left(char* list,unsigned int list_len){
    list_len--;
    for(int i = 0; i < list_len; i++){
        list[i] = list[i+1];

    }

}
bool compare_strings(char* string1, char* string2,unsigned int string_len){
    for(int i = 0; i < string_len; i++){
        if (string1[i] != string2[i]){
            return false;
        }
    }
    return true;
}
char** find_string(int string_count, ...){
    va_list list;
    va_start(list,string_count);
    char* string = va_arg(list,char*);
    unsigned int string_len = str_len(string);
    unsigned int las_index = string_len-1;
    for(int i = 1; i < string_count; i++){
        unsigned int count_lines = 1;
        unsigned int count_indexes = 0;
        char* file_name = va_arg(list,char*);
        char* comparable = malloc(sizeof(char)*string_len);
        FILE* file = fopen(file_name,"r");
        char buff = 'a';
        int count = 0;
        printf("%s \n",file_name);
        for(int i = 0; i < string_len;i++){
            comparable[i] = fgetc(file);
            count_indexes++;
            if (comparable[i] == '\n'){
                count_lines++;
                count_indexes = 0;
            }
            
        }
        if (compare_strings(comparable,string,string_len)){
            printf("Line: %u  Index: %u",count_lines,count_indexes);
        }
        while(1){
            move_values_left(comparable,string_len);
            buff = fgetc(file);
            if (buff == EOF){
                break;
            }
            if (buff == '\n'){
                count_lines++;
                count_indexes = 0;
            }
            comparable[las_index] = buff;
            if (compare_strings(comparable,string,string_len)){
                printf("Line: %u  Index: %u",count_lines,count_indexes);
            }
            

            
        }
    }
}