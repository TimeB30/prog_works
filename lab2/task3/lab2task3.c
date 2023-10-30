#include"funcs.h"

int main(){
    int status = 0;
    find_string(&status,3,"","file1.txt","file2.txt");
    if (status == 1){
        printf("Error, you entered wrong name of file\n");
    }
    else if (status == 2){
        printf("Error, no space allocated\n");
    }
    else if (status == 3){
        printf("Empty string was given\n");
    }



    return 0;
}