#include <stdio.h>

double leave_time(int arr_time, double distance, double speed); 

int main(){

int arrival_time , leave;
double distance,avg_speed;
printf("Enter arrival time as integer on a 24 hour clock. For example, 8:30 PM would be entered as 2030\n");

printf("Arrival time>");
scanf("%d",&arrival_time);
printf("Enter the distance in km>");
scanf("%lf",&distance);
printf("Enter anticipated average speed (including stops) in km/hr>");
scanf("%lf",&avg_speed);
leave=leave_time(arrival_time , distance , avg_speed); 
printf("You need to leave at %d\n",leave);

return 0;
}

double leave_time(int arr_time, double distance, double speed){
	double time;     
        int tot_min, arr_min, dep_tot_min, dep_hr, dep_min, dep_time; 

         time = distance / speed;
         tot_min = (int)(time * 60 + 0.5);
         arr_min = arr_time / 100 * 60 + arr_time % 100;
         dep_tot_min = arr_min - tot_min;
         dep_hr = dep_tot_min / 60;
         dep_min = dep_tot_min % 60;
         dep_time = dep_hr * 100 + dep_min;
         return (dep_time);
      }

