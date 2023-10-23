#include"funcs.c"


int main(int argc, char** argv){
    //say hello

    switch (command_rec(argc,argv))
    {
        case more_than_needs:
			printf("Bad input: You enter more than 2 arguments\n");
			break;
		case less_than_needs:
			printf("Bad input: You did not enter 2 arguments\n");
			break;
        case len:
            printf("hey hey");
            printf("The length is %ld\n",strlen(argv[2]));
            break;

   



    }
return 0;
}