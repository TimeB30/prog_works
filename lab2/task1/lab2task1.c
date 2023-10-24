#include"funcs.c"


int main(int argc, char** argv){
    //say hello
    int* status = malloc(sizeof(int));
    char* string = argv[2];
    long int string_len = strlen(argv[2]);
    switch (command_rec(argc,argv))
    {
        case more_than_needs:
			printf("Bad input: You enter more than 2 arguments\n");
			break;
		case less_than_needs:
			printf("Bad input: You did not enter 2 arguments\n");
			break;
        case len:
            printf("The length is %ld\n",string_len);
            break;
        case reverse_str:
            reverse(string,status);
            if (*status == 1){
                printf("Memore allocation error!\n");
                break;
            }
            printf("%s\n",string);
            break;
        case odd_up:
            odd_up_str(string,status);
            if (*status == 1){
                printf("Memore allocation error!\n");
                break;
            }
            printf("%s \n",string);
            break;
        case num_symb:
            numb_symb_str(string,status);
            if (*status == 1){
                printf("Memore allocation error!\n");
                break;
            }
            printf("%s \n",string);
            break;
        case concatenation:
            
   



    }
return 0;
}