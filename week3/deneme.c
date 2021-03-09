#include <stdio.h>
#include <math.h>

double powerFourByValue(double number);
void powerFourByReference(double *numberpointer);

int main(){


double mynumber = 5;
double * mynumberpointer = &mynumber;

printf("mynumber = %lf\n",mynumber);
printf("&mynumber = %p\n",&mynumber);
printf("mynumberpointer = %p\n",mynumberpointer);
printf("*mynumberpointer = %lf\n",*mynumberpointer);

*mynumberpointer = pow(mynumber,2);

printf("mynumber = %lf\n",mynumber);
printf("&mynumber = %p\n",&mynumber);
printf("mynumberpointer = %p\n",mynumberpointer);
printf("*mynumberpointer = %lf\n",*mynumberpointer);
   
printf("Call by value there is new element to return  : %lf\n",powerFourByValue(mynumber));
printf("mynumber is still 25 : %lf\n",mynumber);
powerFourByReference(&mynumber);
printf("mynumber is now 25*25 becuse we directly change the value of the memorycell which named mynumber : %lf\n",mynumber);
    return 0;

}
double powerFourByValue(double number){return pow(number,4);}
void powerFourByReference(double *numberpointer){ *numberpointer = pow(*numberpointer,4);}
