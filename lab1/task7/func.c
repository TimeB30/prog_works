#include"enums.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
enum flags commande_rec(int argc, char** argv){
    if (argc < 2){
        return wrong_quantity;
    }
    char* flag = argv[1];
    if ((flag[0] != '-') && (flag[0] != '/')){
        return wrong_flag;
    }
    else if (flag[1] == 'r'){
        if (argc != 5){
            return wrong_quantity;
        }
        return mix;
    }
    else if (flag[1] == 'a'){
        if (argc != 4){
            return wrong_quantity;
        }
        return convert;
    }
    else{
        return wrong_flag;
    }
}

void write_to_file(FILE* file1,FILE* file2){
    int ch = 'a';
    while((ch = fgetc(file1)) != EOF){
        if (isalpha(ch)){
            fputc(ch,file2);
            fputc(' ',file2);

        }
    }
    return;

}

void mix_files(FILE* file1,FILE* file2, FILE* outputfile){
    int ch1;
    int ch2;
    int end_status = 0;
    while(1){
        ch1 = fgetc(file1);
        ch2 = fgetc(file2);
        while (!isalpha(ch1)){
            if (ch1 == EOF){
                end_status = 1;
                if (isalpha(ch2)){
                    fputc(ch2,outputfile);
                    fputc(' ',outputfile);
                }
                else{
                    write_to_file(file2,outputfile);
                }
                break;
            }
            ch1 = fgetc(file1);
        }

        while (!isalpha(ch2)){
            if (ch2 == EOF){
                end_status = 1;
                if (isalpha(ch1)){
                    fputc(ch1,outputfile);
                    fputc(' ',outputfile);
                }
                else{
                    write_to_file(file1,outputfile);
                }
                break;
            }
            ch2 =  fgetc(file2);
        }

        if (end_status){
            break;
        }

        fputc(ch1,outputfile);
        fputc(' ',outputfile);
        fputc(ch2,outputfile);
        fputc(' ',outputfile);

    }
}

void convertToLowerCase(int *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void convertToBase4(char *str) {
    while (*str) {
        printf("%o ", (unsigned char)*str);
        str++;
    }
}

void convertToBase8(char *str) {
    while (*str) {
        printf("%o ", (unsigned char)*str);
        str++;
    }
}
int convert_file(FILE* inputFile, FILE* outputFile){
    int ch;
    int count = 0;
    int count_space = 0;
    int buff_size = 1000;
    char* buffer = (char*)malloc(sizeof(char) * buff_size);
    char* new_buffer;
    if (buffer == NULL){
        return 0;
    }
    while ((ch = fgetc(inputFile))!= EOF) {
        count++;
        if (ch == ' '){
            count_space++;
        }
        if (count == (buff_size - 1)){
            buff_size *= 2;
            new_buffer = realloc(buffer,sizeof(char)*buff_size);
            free(buffer);
            if (new_buffer == NULL){
                free(new_buffer);
                return 0;
            }
        }
        if (count_space % 10 == 0) {
            convertToLowerCase(buffer);
            convertToBase4(buffer);
        } else if ((count_space % 2 == 0) || (count_space % 10 != 0)) {
            convertToLowerCase(buffer);
            fprintf(outputFile, "%s ", buffer);
        } else if ((count_space % 5 == 0) || (count_space % 10 != 0)){
            convertToBase8(buffer);
        } else {
            fprintf(outputFile, "%s ", buffer);
        }

        count++;
    }
}





