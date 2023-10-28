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
    unsigned int string_len = strlen(string);
    printf("string len is %d\n",string_len);
    unsigned int las_index = string_len-1;
    for(int i = 1; i < string_count; i++){
        unsigned int count_lines = 1;
        unsigned int count_index = 1;
        char* file_name = va_arg(list,char*);
        char* comparable = malloc(sizeof(char)*string_len);
        FILE* file = fopen(file_name,"r");
        char buff = 'a';
        int count = 0;
        char past_char = 'a';
        printf("%s \n",file_name);
        while(1){
            buff = fgetc(file);
            printf("past %c  buff %c  string %c  count %d line %d\n",past_char,buff,string[count],count,count_lines);
            if (buff == EOF){
                break;
            }
            else if (buff == string[count]){
                comparable[count] = buff; 
                // printf("buff %c  string %c  count %d \n",buff,string[count],count);
                count++;
                if (count == string_len){
                    printf("Line: %u  Index: %u\n",count_lines,count_index);
                     fseek(file,-(sizeof(char)*(count-1)),SEEK_CUR);
                     past_char = comparable[0];
                     count_index++;  
                    count = 0;  
                }
                if (past_char == '\n'){
                count_lines++;
                count_index = 0;
                }                                                      
            }                             
            else{
                if (past_char == '\n'){
                    printf("Nigga\n");
                count_lines++;
                count_index = 0;
                }     
                fseek(file,-(sizeof(char)*(count)),SEEK_CUR);
                past_char = comparable[0];
                count_index++;
                count = 0;  
            }
         past_char = buff;            
    }
}

}


// char** find_string(int string_count, ...){
//     va_list list;
//     va_start(list,string_count);
//     char* string = va_arg(list,char*);
//     unsigned int string_len = strlen(string);
//     unsigned int las_index = string_len-1;
//     for(int i = 1; i < string_count; i++){
//         unsigned int count_lines = 1;
//         unsigned int count_indexes = 0;
//         char* file_name = va_arg(list,char*);
//         char* comparable = malloc(sizeof(char)*string_len);
//         FILE* file = fopen(file_name,"r");
//         char buff = 'a';
//         int count = 0;
//         printf("%s \n",file_name);
//         for(int i = 0; i < string_len;i++){
//             comparable[i] = fgetc(file);
//             count_indexes++;
//             if (comparable[i] == '\n'){
//                 count_lines++;
//                 count_indexes = 0;
//             }
            
//         }
//         if (compare_strings(comparable,string,string_len)){
//             printf("Line: %u  Index: %u\n",count_lines,count_indexes-string_len);
//         }
//         while(1){
//             move_values_left(comparable,string_len);
//             buff = fgetc(file);
//             count_indexes++;
//             if (buff == EOF){
//                 break;
//             }
//             if (buff == '\n'){
//                 count_lines++;
//                 count_indexes = 0;
//             }
//             comparable[las_index] = buff;
//             if (compare_strings(comparable,string,string_len)){
//                 printf("Line: %u  Index: %u\n",count_lines,count_indexes-string_len);
//             }
//         }
//     }
// }





 // else if ((buff == '\n') && (count == 1)){  //или count == 1
            //     printf("%s\n",comparable);
            //     count_lines++;
            //     count_index = 1;
            //     // printf("up");
            // }    