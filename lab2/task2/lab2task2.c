#include"funcs.c"


int main(){
    int status = 0;
    double value = average_geom_value(&status,3,1,2,2);
    printf("%lf\n",value);

    double value2 = fast_pow(3,-3);
    printf("%lf \n",value2);
    

    return 0;
}