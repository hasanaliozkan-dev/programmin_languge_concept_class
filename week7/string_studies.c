#include <stdio.h>
#include <string.h>
#define SIZE 100
int main(){
/*
char  myString[SIZE];
 for(scanf("%s",myString); myString[0] !='b';scanf("%s",myString))
    printf("%s starts with the letter %c\n",myString,myString[0]);
 */
/* printf("Please enter a sentece :\n");
gets(myString);
printf("Your sentence is : %s\n",myString);
int isOK = puts(myString);
printf("\n%d\n",isOK);
 */
/* It is not valid. -> myString = "anything else";*/

/*
char  myString[SIZE] = "hasan ali ozkan";

for (int i = 0; i < SIZE; i++)
{
    if(myString[i] == '\0')
        printf("NULL %d\n",i);
    else if (myString[i] == ' ')
        printf("SPACE %d\n",i); 
    else
        printf("%c\n",myString[i]);
}

puts(myString);

 */

char  source[SIZE] = "hasan,ali,ozkan";
char destination[SIZE];
char destination1[SIZE];

strcpy(destination,source);
puts(destination);
strncpy(destination1,source,5);
puts(destination1);
strcat(destination,destination1);
puts(destination);
int a = strcmp("hij","hij");
printf("%d\n",a);
int length= strlen(destination);
printf("%d\n",length);
int i = 0;
while(i<length){
    puts(strtok(destination,','));
}





return 0;
}