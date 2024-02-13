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
    fputc('\0',file2);
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

void add_num_to_buff(FILE* file,char* buff, int index, int num){
    do {
        char char_num = (num % 10) + 48;
        buff[index] = char_num;
        index++;
        num = num / 10;
    } while(num != 0);
}
void convertToLowerCase(char *str, int index) {
    for (int i = 0; i < index; i++) {
        str[i] = tolower(str[i]);
    }
}

void convertasciiToBaseX(int base,char* ch,int*status,int* index,int* buff_size) {
    int base4_num = 0;
    char char_num;
    int size = 100;
    int i = 0;
    unsigned char ch_ascii = (unsigned char)*ch;
    char* answer = (char*)malloc(sizeof(char) * size);
    if (answer == NULL){
        return;
        *status = 1;
    }
    int t = 0;
    while (ch[t] < *index){
    ch_ascii = ch[t];
    base4_num = 0;
        while (ch_ascii != 0) {
            base4_num += ch_ascii % base;
            base4_num *= 10;
            ch_ascii /= base;
    }
    do{
        if (i == (size-1)){
                size *= 2;
                char* new_answer = (char*)realloc(answer,sizeof(char*) * size);
                free(answer);
                if (new_answer == NULL){                    
                    *status = 1;
                    return;
                }
                answer = new_answer;
        }
        char_num = (base4_num % 10) + 48;
        ch_ascii = ch_ascii / 10;
        answer[i] = char_num;
        i++;
    }
    while(ch_ascii != 0);
    t++;
    }
    ch = answer;
    *index = i;
    *buff_size = size;
    return;
}

int convert_file(FILE* inputFile, FILE* outputFile){
    int status = 0;
    int ch;
    int index = 0;
    int space_status = 0;
    int count_space = 0;
    int buff_size = 100;
    char* buffer = (char*)malloc(sizeof(char) * buff_size);
    char* new_buffer;
    int t = 0;
    if (buffer == NULL){
        return 0;
    }
    while ((ch = fgetc(inputFile))!= EOF) {
        if (index == (buff_size - 1)){
            buff_size *= 2;
            new_buffer = realloc(buffer,sizeof(char)*buff_size);
            free(buffer);
            if (new_buffer == NULL){
                return 0;
            }
            else{
                buffer = new_buffer;
            }
        }
        if (isalnum(ch)){
            buffer[index] = ch;
            space_status = 1;
            index++;
        }
        else{
            if (space_status == 1){
                buffer[index] = ch;
                space_status = 0;
                count_space++;
                index++;
            }

        }
        if ((count_space % 10 == 0) && (count_space != 0)) {
            convertToLowerCase(buffer,index);
            convertasciiToBaseX(4,buffer,&status,&index,&buff_size);
        } else if ((count_space % 2 == 0) && (count_space % 10 != 0)) {
            convertToLowerCase(buffer,index);
        } else if ((count_space % 5 == 0) && (count_space % 10 != 0)){
            convertasciiToBaseX(8,buffer,&status,&index,&buff_size);
        }
    }
    for (int i = 0; i < index; i++){
        fputc(buffer[i],outputFile);
    }
    return 1;
}





