#include"func.c"



int main(int argc, char* argv[]){
    long double epsilon = eps();
    unsigned int n = 2;
    long double first_val = 1;
    long double value = first_val * 2.0;
    while(1){
        long double second_val = first_val*1/n;
        if (fabs(first_val - second_val) > 0.0001){
            value += second_val;
            printf("\nsec val == %.100Lf\n",second_val);
             printf("\n%.100Lf\n",value);
            first_val = second_val;
            n++;
        }
        else{
            printf("\nshiit\n");
            break;
        }

    }
    printf("\n%.10Lf\n",value);



    return 0;
}