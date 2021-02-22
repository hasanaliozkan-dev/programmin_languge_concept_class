#include <stdio.h>
#define ONE_CUB_MASS 1000
#define G 9.80
#define EFFICIENCY 0.90

int main(){

double height,cube_mass_in_sec,total_water_mass,
work,energy,mw;
printf("Please enter the height of the water in meters : ");
scanf("%lf",&height);
printf("Please enter the number of cubic in a sec : ");
scanf("%lf",&cube_mass_in_sec);
total_water_mass = ONE_CUB_MASS*cube_mass_in_sec;
work = total_water_mass*G*height;
energy = work*EFFICIENCY;
mw = energy*1.0e-6;
printf("%f MW energy produced by water",mw);




return 0;
}
