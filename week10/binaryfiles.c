#include <stdio.h>
#include <stdlib.h>

int main(){


    FILE *b1,*b2;
    int scores[5] = {5,10,23,56,78};
    b1 = fopen("nums.bin","wb");
    b2 = fopen("arraynums.bin","wb");
    for (int i = 0; i < 500; i++)
    {
        fwrite(&i,sizeof(int),1,b1);
    }
    fwrite(scores,sizeof(int),5,b2);


    




    return 0;
}