#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXAPP 50 //Max # of applicants.
#define MAXNAMELENGTH 30 // Max name length.

int alpha_first(char *list[],int min_sub,int max_sub);
void selec_sort_str(char *list[],int n);
int main(){


    char applicants[MAXAPP][MAXNAMELENGTH];
    char * alpha[MAXAPP];
    int num_applicants;
    char temp;
    printf("Please enter number of applicants : (0  .   .  %d) ",MAXAPP);
    
    scanf("%d",&num_applicants);
    //If you dont do this the gets function read the rest of the line in here and read one line minus.
    do
    {
        scanf("%c",&temp);
    } while (temp!='\n');
    
    
    printf("Enter name of applicants on seperate lines of less than %d characters in the order in which they applied :\n",MAXNAMELENGTH);
   
    for (int i = 0; i < num_applicants; ++i)
    {
        gets(applicants[i]);
    }
    for (int i = 0; i < num_applicants; i++)
    {
        alpha[i] = applicants[i];
    }
    selec_sort_str(alpha,num_applicants);

    for (int i = 0; i < num_applicants; i++)
    {
        int len = strlen(applicants[i]);
        for (int j = 0; j < len; j++)
        {
            applicants[i][j]= toupper(applicants[i][j]);
        }
        
    }
    
   
    printf("\n\n%-30s%5c%-30s\n\n","Application Order",'    ',"Alphabetical Order");
    for (int i = 0; i < num_applicants; i++)
    {
        printf("%-30s%5c%-30s\n",applicants[i],'    ',alpha[i]);
    }
    




    return 0;
}

void selec_sort_str(char *list[],int n){
    int min;
    char* temp;
    for (int i = 0; i < n-1; i++)
    {
        min = alpha_first(list,i,n-1);
        if(min != i){
            temp = list[min];
            list[min] = list[i];
            list[i] = temp;
        }
    }
    
}

int alpha_first(char *list[],int min_sub,int max_sub){

    int first = min_sub;
    for (int i = min_sub+1; i <= max_sub; i++)
    {
        if (strcmp(list[i],list[first])<0)
        {
            first = i;
        }
        
    }
    return first;
}