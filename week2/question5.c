#include <stdio.h>

int is_prime(int number,int i);

int main()
{
    int number, check;
    printf("Enter a number: ");
    scanf("%d", &number);
    check = is_prime(number, number / 2);
    if (check == 1)
    {
        printf("%d is a prime number\n", number);
    }
    else
    {
        printf("%d is not a prime number\n", number);
    }
    return 0;
}



int is_prime(int number, int i){
    if (i == 1)
    {
        return 1;
    }
    else
    {
       if (number % i == 0)
       {
         return 0;
       }
       else
       {
         return is_prime(number, i - 1);
       }       
    }
}

