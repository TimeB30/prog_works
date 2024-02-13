#include"func.c"
#include<ctype.h>
int main(int argc,char** argv){
    FILE* file1;
    FILE* file2;
    FILE* outputfile;
    int ch1 = 1;
    int ch2 = 1;
    int end_status = 0;
    char* buff;
    switch (commande_rec(argc,argv)) {
        case wrong_flag:
            printf("Wrong flag\n");
            break;
        case wrong_quantity:
            printf("Wrong quantity of arguments\n");
            break;
        case mix:
            printf("%s\n",argv[2]);
            file1 = fopen(argv[2],"r");
            file2 = fopen(argv[3],"r");
            outputfile = fopen(argv[4],"w");
            if ((file1 == NULL) || (file2 == NULL) || (outputfile == NULL)) {
                printf( "Error: can't open file");
                return 0;
            }
            mix_files(file1,file2,outputfile);
            fclose(file1);
            fclose(file2);
            fclose(outputfile);
            break;
        case convert:
            file1 = fopen(argv[2],"r");
            file2 = fopen(argv[3],"w");
            if ((file1 == NULL) || (file2 == NULL)){
                printf( "Error: can't open file\n");
                return 0;
            }
            buff = malloc(sizeof(char) * 1000);
            if (buff == NULL){
                printf("Momory allocation error\n");
                return 0;
            }
            if (convert_file(file1,file2)){
                printf("Done\n");
            }
            else{
                printf("Memory allocation error");
            }





            break;

    }



    return 0;
}