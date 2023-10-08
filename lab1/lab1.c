#include"func_lib.c"


int main(int argc, char** argv) {
	printf("\nhelloo niggers");
	switch (command_rec(argc,argv)) {
		case more_than_needs:
			printf("Bad input: You enter more than 2 arguments\n");
			break;
		case less_than_needs:
			printf("Bad input: You did not enter 2 arguments\n");
			break;
		case not_number:
			printf("You enter not a number\n");
			break;
		case wrong_flag:
			printf("You enter wrong flag\n");
			break;
		case multiplicity:{
			
			int number = char_to_int(argv)[0];			
			if (number == 0){
				printf("Can not divide by 0\n");
				break;
			}
			int* result = narutal_multiplicities(number);
			int i = 0;
			while(true){
				if (result[i] == -5){
					break;
				}
				printf("%d ",result[i]);
				i += 1;
			}
			printf("\n");
			break;
		}
		case simp_comp_check:{
			int number = char_to_int(argv)[0];
			int is_simple =  check_to_simple(number);
			if (is_simple == 1){
				printf("Number is simple \n");
			}
			else if (is_simple == 3){
				printf("Number is not simple and not compound\n");
			}
			else{
				printf("Number is compound \n");
			}
			break;
		}
		case separate:{
			int zero_indicator = 1;
			while (true){
				for (int i = 0; i < strlen(argv[2]); i++){
					if (zero_indicator){
						if (argv[2][i] != '0'){
							printf("%c ",argv[2][i]);
							zero_indicator = 0;				
				    	}
					}	
					else{
						printf("%c ",argv[2][i]);
					}
				}
				break;
			}
			printf("\n");
		break;
		}
		case degree_table:{
			int number = char_to_int(argv)[0];
			if (number < 1){
				printf("Number is lower than 1\n");
				break;
			}
			else if (number > 10){
				printf("Number is bigger than 10\n");
				break;
			}
			printf("%13d  ",1);
			for (int i = 2; i < number+1; i++){
				printf("%11d  ",i);
			}
			printf("\n\n\n\n");
			for (int i = 1; i < 11; i++){
				printf("%2d",i);
				for(int n = 1; n < number + 1; n++){
					printf("%11lld  ",plow(i,n));
				}
				printf("\n\n\n\n");
			}
			break;
		}
		case summ_numbers:{
			int number = char_to_int(argv)[0];
			if (number < 1){
				printf("Number is lower than 1\n");
				break;
			}
			unsigned long long int summ = 1;
			summ = (1+number)*number/2;
			printf("%llu\n",summ);
			break;
		}
		case factorial:{ 
			int number = char_to_int(argv)[0];
			
			if (number == 0){
				printf("0\n");
			}
			else if (number < 0){
				printf("The number is smaller than 0\n");
			}
			else if (number > 20){
				printf("The number is too big\n");
			}
			else{
				unsigned long long int result = fctrl(number);
				printf("\n%llu",result);
			}
			break;
		}
		
		
	}
	return 0;
}
