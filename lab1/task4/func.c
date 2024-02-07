#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"enums.h"

enum flags command_rec(int argc, char** argv){
//    printf("%d \n",argc);
    if (argc < 3){
        return wrong_quantity;
    }
    char* flag = argv[1];
    if ((flag[0] != '/') && (flag[0] != '-') ){
        return wrong_flag;
    }
    else if (flag[1] == 'n'){
        if (argc != 4){
            return wrong_quantity;
        }
        else if ((flag[2] != 'd') && (flag[2] != 'i') && (flag[2] != 's') && (flag[2] != 'a')){
            return wrong_flag;
        }
        else{
            return own_file;
        }
    }
    else if (argc != 3){
        return wrong_quantity;
    }
    else if ((flag[1] != 'd') && (flag[1] != 'i') && (flag[1] != 's') && (flag[1] != 'a')){
        return wrong_flag;
    }



}

enum flags detect_command(char** argv, int switch_status){
    char flag;
    if (switch_status == 1){
        flag = argv[1][2];
    }
    else{
        flag = argv[1][1];
    }

    if (flag == 'd'){
        return d;
    }
    else if (flag == 'i'){
        return i;
    }
    else if (flag == 's'){
        return s;
    }
    else if (flag == 'a'){
        return a;
    }

}

void delete_number(FILE* inputfile, FILE* outputfile){
    int ch;
    while ((ch = fgetc(inputfile)) != EOF){
        if (!isdigit(ch)){
            fputc(ch,outputfile);
        }
    }
}
void write_int(int num, FILE* outputfile){
    int buff[10];
    int i = -1;
    do{
        i++;
        buff[i] = ((num % 10) + 48);
        num = (int)(num / 10);
    } while (num != 0);
    for (int t = i; t > -1; t--){
        fputc(buff[t],outputfile);
    }
}
void count_latin_letter(FILE* inputfile, FILE* outputfile){
    int ch = '1';
    int count = 0;
    int string_count = 1;
    while (ch != EOF){
        ch = fgetc(inputfile);
        if (isalpha(ch) && isascii(ch)){
            count += 1;
        }
        if ((ch == '\n') || (ch == EOF)){
            fputs("Строка №",outputfile);
            write_int(string_count,outputfile);
            fputs(": ",outputfile);
            write_int(count,outputfile);
            fputc('\n',outputfile);
            count = 0;
            string_count += 1;
        }

    }
}
void count_except(FILE* inputfile, FILE* outputfile) {
    int ch = '1';
    int count = 0;
    int string_count = 1;
    while (ch != EOF) {
        ch = fgetc(inputfile);
        if (!isalnum(ch) && !isspace(ch)) {
            count += 1;
        }
        if ((ch == '\n') || (ch == EOF)) {
            printf("%d\n", count);
            fputs("Строка №", outputfile);
            write_int(string_count, outputfile);
            fputs(": ", outputfile);
            write_int(count, outputfile);
            fputc('\n', outputfile);
            count = 0;
            string_count += 1;
        }

    }
}
void change_to_ascii(FILE* inputfile,FILE* outputfile){
    int ch;
    while((ch = fgetc(inputfile)) != EOF){
        if (!isdigit(ch)){
            fprintf(outputfile,"%02X",ch);
        }
        else{
            fputc(ch,outputfile);
        }
    }
}

