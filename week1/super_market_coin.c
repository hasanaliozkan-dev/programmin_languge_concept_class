#include <stdio.h>

int main(){
    char c1,c2,c3;
    int coins,quarters,dimes,nickels,pennies,total_cents,total_dollars,change;

    printf("Please write your name in three letters : ");
    scanf("%c%c%c",&c1,&c2,&c3);

    printf("\n%c%c%c please enter your coin information.\n",c1,c2,c3);
    printf("Number of $ coins : ");
    scanf("%d",&coins);
    printf("Number of quarters : ");
    scanf("%d",&quarters);
    printf("Number of dimes : ");
    scanf("%d",&dimes);
    printf("Number of nickels : ");
    scanf("%d",&nickels);
    printf("Number of pennies : ");
    scanf("%d",&pennies);

    total_cents = coins*100 + quarters*25 + dimes*10 + nickels*5 + pennies;
    total_dollars = total_cents/100;
    change = total_cents%100;

    printf("\n%c%c%c Coin Credit \n",c1,c2,c3);
    printf("Dollars : %d\n",total_dollars);
    printf("Change : %d\n",change);
    

}