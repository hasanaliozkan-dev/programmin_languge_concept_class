#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CipherMethods.h"





int main(){
char text[500];
char passcode[9] = "ceng2002";
printf("** You are about to enter a very secret cryptography service called CENG 2002 C - Secret Coded System **\n");
printf("Enter your text : ");
gets(text);
encryptCaesar(text); 

system("clear");
int attempt= 0;
while (1)
{
    printf("In order to see the encrypted message, enter your passcode:\n");
    char inputCode[9];
    gets(inputCode);
    if(strcmp(inputCode,passcode)==0){
       printf("Cipher: %s\n",text );
       char ans;
       printf("Would you like to convert the cipher to original text (Y/N)?\n");
       ans= getchar();
       if(ans == 'Y'){
           decryptCaesar(text);
           printf("%s\n",text);
           printf("Original text and the decrypeted text match.\n");
       }break;
       
    }
    else{
        printf("Wrong passcode enter again: ");
        attempt++;
    }
    if (attempt >=3)
    {
        printf("Number of allowed attempts has been reached without successful entry!\n");
        printf("Your IP has been blacklisted by us. Good luck!!\n");
        break;
    }
    
}

    return 0;
}