#include <stdio.h>
#include <math.h>
#define LENGTH 8

int main(){
    double myArr[LENGTH];
    double mean,standart_deviation,sum,sum_sqr;
    printf("Enter %d numbers space seperated by blanks or <return>s ",LENGTH);
    int i = 0;
    while (i<LENGTH)
    {
        scanf("%lf",&myArr[i]);
        i++;
    }
    i= 0;
    while (i<LENGTH)
    {
        sum += myArr[i];
        sum_sqr += pow(myArr[i],2);
        i++;
    }
    mean = sum/LENGTH;
    standart_deviation = sqrt((sum_sqr / sum)-pow(mean,2));
    printf("The mean is: %0.2lf .\n",mean);
    printf("The standart deviation is : %0.2lf .\n",standart_deviation);
    printf("Table of differences between data values and mean\n");
    printf("Index\tItem\tDifference\n");
    i = 0;
    while (i<LENGTH)
    {
        printf("%d\t%0.2lf\t%0.2lf\n",i,myArr[i],myArr[i]-mean);
        i++;
    }
    
    return 0;
}