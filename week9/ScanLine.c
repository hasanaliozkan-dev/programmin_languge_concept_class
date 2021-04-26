#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * scanLine(char*output,int length){
    int i =0;
    char temp ;
    printf("Enter a line\n");
    do{
        temp= getchar();
        output[i++] = temp;
        
    }while(temp!='\n'&&temp!=EOF&&i<length);

while(temp!='\n'&&temp!=EOF){
    temp = getchar();
}
return output;
}

int main(){
char output[50];
scanLine(output,50);
puts(output);

return 0;

}