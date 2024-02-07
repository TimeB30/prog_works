#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc, char** argv){
    FILE* file = fopen(argv[1],"r");
    char ch1 = fgetc(file);
    char ch2 = fgetc(file);
    if (ch1 == EOF){
        printf("first eof");
    }
    if (ch2 == EOF){
        printf("Second EOF");
    }
    if (isalpha(ch2)){
        printf("it's letter");
    }
    return 0;
}