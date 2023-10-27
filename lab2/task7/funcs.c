 #include"enums.h"




 double find_root(int left_border, int right_border, double eps,double (*equation_ptr)(int),double* status){
    double result  = equation_ptr(3);
    double answer = 0;
    if ((left_border > result) || (right_border < result)){
        *status = 1;
        return answer;
    }
    else if (eps < 0){
        *status = 2;
        return answer;
    }
    while(abs(result - answer) > eps){       
        answer =  (right_border+left_border)/2;
        if (answer > result){
            right_border = answer;
        }
        else{
            left_border = answer;
        }
         printf("result %lf  answer   %lf\n",result, answer);
    }
}

enum flags find_root_debug(int status){
    if (status == 1){
        return not_in_range;
    }
    else if (status == 2){
        return negative_eps;
    }

}