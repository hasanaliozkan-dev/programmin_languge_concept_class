#include <stdio.h>
#include <string.h>
#define SIZE 20
void selectionSort(char list[][SIZE],int n);
int first(char list[][SIZE],int min,int max);

int main(){
        char mylist[5][SIZE]= {"xyz","abc","acb","zte","abz"};
        selectionSort(mylist,5);
        for (int i = 0; i < 5; i++)
        {
            puts(mylist[i]);
        }
        



    return 0;
}



int first(char list[][SIZE],int min,int max){
    int f,i;
    f = min;
    for(i=min+1;i<=max;i++){
            if(strcmp(list[i],list[f])<0){
                f = i;
            }
    }
    return f;
}
void selectionSort(char list[][SIZE],int n){
    int fill,index_min;
    char temp[SIZE];    
    for (fill = 0; fill < n-1; ++fill){
        index_min = first(list,fill,n-1);

        if(index_min != fill){
            strcpy(temp,list[index_min]);
            strcpy(list[index_min],list[fill]);
            strcpy(list[fill],temp);
        }
    }
      





}