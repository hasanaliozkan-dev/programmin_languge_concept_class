#include <stdio.h>
#define PI 3.14159
int main(){

double radius,area,circumf;
int num_circ;
char circ_name;
int input = 0;
while (1){
printf("\nPlease enter the name of your circle with just one char : ");
scanf("%c",&circ_name);
printf("\nPlease enter radius of your circle : ");
scanf("%lf",&radius);
area = PI*radius*radius;
circumf = 2.0*PI*radius;
printf("\nThe area of the \"%c\" circle is \"%lf\"\n",circ_name,area);
printf("\nThe circumstance of the \"%c\" circle is \"%lf\"\n",circ_name,circumf);
printf("\nIf you want to exit please press \"1\" otherwise press any key to continue : ");
scanf("%d",&input);
if(input ==1){
break;
}
}









return 0;
}
