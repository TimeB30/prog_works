#include"func.c"
#include<string.h>

int main(int argc, char** argv){
    int switch_status = 0;
    switch (command_rec(argc, argv)) {
        case wrong_quantity:
            printf("Wrong quantity of arguments\n");
            return 0;
        case wrong_flag:
            printf("Wrong flag\n");
            return 0;
        case own_file:
            switch_status = 1;
            break;
    }
    char* output_name;
    FILE* inputfile = fopen(argv[2],"r");
    if (inputfile == NULL){
        printf("Input file doesn't exist\n");
        return 0;
    }
    FILE* outputfile;
    if (switch_status == 1){
        output_name = argv[3];
        outputfile = fopen(output_name,"r+");
        if (outputfile == NULL){
            printf("Output file doesn't exist\n");
            return 0;
            }
        }
    else {
        char auto_name[4] = "out_";
        int buff_size = strlen(argv[2]) + 4;
        char* result =  (char*)malloc(buff_size*sizeof(char));
        if (result == NULL){
            printf("Memory allocation error\n");
            return 0;
        }
        strcpy(result,auto_name);
        strcat(result,argv[2]);
        output_name = result;
        outputfile = fopen(output_name,"w");
        free(result);
    }
    int ch;
    switch(detect_command(argv,switch_status)){
        case d:
            delete_number(inputfile,outputfile);
            break;
        case i:
            count_latin_letter(inputfile,outputfile);
            break;
        case s:
            count_except(inputfile,outputfile);
            break;
        case a:
            change_to_ascii(inputfile,outputfile);
            break;
    }

    fclose(inputfile);
    fclose(outputfile);

    return 0;
}