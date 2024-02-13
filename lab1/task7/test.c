#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
// char* ascii_to_4(char* string){
//     char new_string = malloc(sizeof(char) * 100);
//     return new_string;
// }
int main(int argc, char** argv){
    int i = 0;
    int t = 0;
    char* string = argv[1];
    char* string2 = (char)malloc(sizeof(char)*10);
    while(string[i] != '\0'){
        printf("done");
        i++;
    }
    while(string2[t] != '\0'){
        print("Done");
        i++;
    }
    return 0;
}