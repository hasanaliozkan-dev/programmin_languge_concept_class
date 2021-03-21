#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*The regula falsi, method of false position, or false position method is a very old method for solving an equation with one unknown,
that, in modified form, is still in use. 
In simple terms, the method is the trial and error technique of using test ("false") values for the variable 
and then adjusting the test value according to the outcome. This is sometimes also referred to as "guess and check".
Versions of the method predate the advent of algebra and the use of equations.*/
FILE * fileptr;

float arb_func(float value);
void regular_falsi(float *x,float x0,float x1,float fx0,float fx1,int *itr);
int main(){
    int itr=0,maxitr;
    float x0,x1,x_curr,x_next,error;

    printf("Enter interval values [x0,x1], allowed error and number of iterations:");
    scanf("%f%f%f%d",&x0,&x1,&error,&maxitr);
    regular_falsi(&x_curr,x0,x1,arb_func(x0),arb_func(x1),&itr);
    fileptr = fopen("activity_output.txt","w");
    fprintf(fileptr,"Iteration %d: %0.4f\n",itr,x_curr);
    
    do
    {
        if(arb_func(x0)*arb_func(x_curr)<0){
            x1 = x_curr;
        }else{
            x0 = x_curr;
        }
        regular_falsi(&x_next,x0,x1,arb_func(x0),arb_func(x1),&itr);
        if(fabs(x_next-x_curr)<error){
            printf("After %d iterations,root is %0.5f\n",itr,x_curr);
            fprintf(fileptr,"After %d iterations,root is %0.5f\n",itr,x_curr);
            
            return 0;
        }
        fprintf(fileptr,"Iteration %d: %0.5f\n",itr,x_curr);
        x_curr=x_next;

    } while (itr<maxitr);
    printf("\nSolutions does not converge or iterations not sufficient:\n");
    fprintf(fileptr,"\nSolutions does not converge or iterations not sufficient:\n");
    
    return 1;
}

float arb_func(float value){
    return value*log10(value) - 1.2;
}
void regular_falsi(float*x,float x0,float x1,float fx0,float fx1,int*itr){
    *x = (x0*fx1-x1*fx0)/(fx1-fx0);
    *itr = *itr+1;
    printf("Iteration %d: %0.5f\n",*itr,*x);
        
   
}