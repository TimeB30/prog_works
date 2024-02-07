
#include"func.c"


int main(int argc, char* argv[]){
    int status = 0;
    char* end1;
    char* end2;
    char* end3;
    char* end_eps;
    long double a,b,c,epsilon;
    long double** answer_quadratic;
    switch(command_rec(argc,argv)){
        case quadratic:
            a = strtold(argv[2],&end1);
            if (end1 == argv[2]){
                printf("Error: wrong input argument\n");
                break;
            }
            b = strtold(argv[3],&end2);
            if (end2 == argv[3]){
                printf("Error: wrong input argument\n");
                break;
            }
            c = strtold(argv[4],&end3);
            if (end2 == argv[3]){
                printf("Error: wrong input argument\n");
                break;
            }
            answer_quadratic = solveQuadratic(a,b,c,&status);
            if (status == 1){
                printf("Memory allocation error\n");
                clear_memory(answer_quadratic,6);
                break;
            }
            for (int i = 0; i < 6; i++){
                if (answer_quadratic[i][3] == 0){
                    printf("%Lf %Lf %Lf : no root\n",answer_quadratic[i][0],answer_quadratic[i][1],answer_quadratic[i][2]);
                }
                else if (answer_quadratic[i][3] == 1){
                    printf("%Lf %Lf %Lf : %Lf\n",answer_quadratic[i][0],answer_quadratic[i][1],answer_quadratic[i][2],answer_quadratic[i][4]);
                }
                else{
                    printf("%Lf %Lf %Lf : %Lf %Lf\n",answer_quadratic[i][0],answer_quadratic[i][1],answer_quadratic[i][2],answer_quadratic[i][4],answer_quadratic[i][5]);
                }
            }
            clear_memory(answer_quadratic,6);
            break;
        case triangle:
            epsilon = strtold(argv[2],&end_eps);
            if (end_eps == argv[2]){
                printf("Error: wrong input argument\n");
                break;
            }
            a = strtold(argv[3],&end1);
            if (end1 == argv[3]){
                printf("Error: wrong input argument\n");
                break;
            }
            b = strtold(argv[4],&end2);
            if (end2 == argv[4]){
                printf("Error: wrong input argument\n");
                break;
            }
            c = strtold(argv[5],&end3);
            if (end3 == argv[5]){
                printf("Error: wrong input argument\n");
                break;
            }
            if(isRightTriangle(a,b,c,epsilon)){
                printf("It's triangle\n");
            }
            else{
                printf("It's not triangle\n");
            }
            break;

        case multiplicity:
            a = strtold(argv[2],&end1);
            if (end1 == argv[2]){
                printf("Error: wrong input argument\n");
                break;
            }
            b = strtold(argv[3],&end2);
            if (end2 == argv[3]){
                printf("Error: wrong input argument\n");
                break;
            }

            if (isMultiple(a,b)){
                printf("Can be multiplied\n");
            }
            else{
                printf("Can't be multiplied\n");
            }
            break;

        case wrong_quantity:
            printf("Wrong quantity of values\n");
            break;
        case wrong_input:
            printf("Error: wrong input or flag\n");
            break;
    }

    return 0;
}