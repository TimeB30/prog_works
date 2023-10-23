#include"funcs.c"


int main(int argc, char** argv){
    //say hello
    int status = 0;
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
            printf("%s\n",revese(string,status));
            break;

   



    }
return 0;
}