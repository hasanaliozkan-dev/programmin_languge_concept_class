#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char inputName[32],backupName[32];
    char temp;
    printf("Please enter name of the input file>");
    scanf("%s",inputName);
    printf("Please enter name of the backup file>");
    scanf("%s",backupName);
    FILE *input = fopen(inputName,"r");
    FILE *backup = fopen(backupName,"w");
    while(1){
        temp = getc(input);
        if(temp==EOF)
            break;
        fprintf(backup,"%c",temp);
    }
    
    

}