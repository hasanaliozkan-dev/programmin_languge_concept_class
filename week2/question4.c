#include <stdio.h>

int power_raiser(int base, int power);
int main(){

int base,power;
printf("Please enter a base : ");
scanf("%d",&base);
printf("Please enter a power : ");
scanf("%d",&power);
printf("The answer is %d\n",power_raiser(base,power));


return 0;
}

int power_raiser(int base, int power){
	int ans;
	if(power == 1)
		ans = base;
	else
		ans = base*power_raiser(base,power-1);
	return ans;

}

