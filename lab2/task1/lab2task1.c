#include"funcs.c"
int main(int argc, char** argv){
    int* status = malloc(sizeof(int));
    char* string;
    char* end;
    int string_quantity;
    int* concat_result;
    switch (command_rec(argc,argv))
    {
        case more_than_needs:
			printf("Bad input: You enter more than 2 arguments\n");
			break;
		case less_than_needs:
			printf("Bad input: You did not enter 2 arguments\n");
			break;
        case wrong_flag:
            printf("You enter wrong flag\n");
            break;
        case len:
            printf("The length is %ld\n",strlen(argv[2]));
            break;
        case reverse_str:
            string = argv[2];
            reverse(string,status);
            if (*status == 1){
                *status = 0;
                printf("Memore allocation error!\n");
                break;
            }
            printf("%s\n",string);
            break;
        case odd_up:
            string = argv[2];
            odd_up_str(string,status);
            if (*status == 1){
                *status = 0;
                printf("Memore allocation error!\n");
                break;
            }
            printf("%s \n",string);
            break;
        case num_symb:
            string = argv[2];
            numb_symb_str(string,status);
            if (*status == 1){
                *status = 0;
                printf("Memore allocation error!\n");
                break;
            }
            printf("%s \n",string);
            break;
        case concatenation:
            string_quantity = strtol(argv[2],&end,10);
            if (string_quantity == 0){
                printf("Error, you didn't enter  a number of strings\n");
                break;
            }
            else if (string_quantity < 0){
                printf("Error, you  enter  a negative number of strings\n");
                break;
            }
            concat_result = concatenation_str(argv,&argc,status,string_quantity);
            if (*status == 1){
                *status = 0;
                printf("Memore allocation error, or you entered less or more parameters than you should!\n");
                break;
            }
            for (int i = 0; i < string_quantity;i++){
                unsigned int index = concat_result[i];
                printf("%s ",argv[index + 2]);

            }
            free(concat_result);
            concat_result = NULL;           
    }
return 0;
}