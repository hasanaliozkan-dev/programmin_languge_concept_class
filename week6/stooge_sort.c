#include <stdio.h>
#include <math.h>
// Prints the array with size, size
void printArray(const int arr[], const int size);
// Swaps the values pointed by p and k
void swap(int* p, int* k);
// Recursive function, low and high are array indices
void stoogeSort(int arr[], const int low, const int high);

int main(){
    int size;
    //Getting input from the user.
    printf("Enter the array size: ");
    scanf("%d",&size);
    int  arr[size];
    printf("Enter %d elements: ",size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    //Giving output to the user.
    printArray(arr,size);
    printf("Sorted Array:\n");
    stoogeSort(arr,0,size-1);
    printArray(arr,size);
    
    
    return 0;
}
//Print the array 
void printArray(const int arr[],const int size){
    int i =0;
    while(i<size){
        if(i==size-1){
            printf("%d",arr[i]);
        }else{
            printf("%d,",arr[i]);
        }
        
        i++;
    }
    printf("\n");
}

//swapping two elements by using pointers.
void swap(int *p,int *k){
    int temp = *p;
    *p=*k;
    *k=temp;
}

/*Stooge sort is a recursive sorting algorithm.
It is notable for its exceptionally bad time 
complexity of O(nlog(3)/log(1.5) ) = O(n^2.7095...).*/
void stoogeSort(int arr[], const int low, const int high){
    //If the low and high are equal the function done.
    if(low>=high){
        return;
    }
    //If left item is greater than right item.
    if(arr[low] > arr[high]){
        //Swap them by using swap function.
        swap(&arr[low],&arr[high]);
    }
    //If there are more than 2 elements left in the current function call.       
    if((high-low +1)>2){
        int temp = floor((high-low +1)/3);
        //Call stoogesort for the first 2/3'rd of the array.
        stoogeSort(arr,low,high-temp);
        //Call stoogesort for the last 2/3'rd of the array.
        stoogeSort(arr ,low + temp,high);
        //Call again stoogesort for the first 2/3'rd of the array.
        stoogeSort(arr,low,high-temp);
    }
}



