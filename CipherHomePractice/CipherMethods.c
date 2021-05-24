#include "CipherMethods.h"
#include <stdlib.h>
#include <stdio.h>

char * encryptCaesar(char * input){

for (int i = 0; input[i] != '\0'; i++)
{
   
   char ch = input[i];
   if(ch >='a' && ch<= 'z' ){
       ch = ch + CAESAR_SHIFT;
       if(ch>'z'){
           ch = ch - NUMBER_OF_LETTERS;
       }
       input[i] = ch;
   }else if(ch >='A' && ch<= 'Z' ){
       ch = ch + CAESAR_SHIFT;
       if(ch>'Z'){
           ch = ch - NUMBER_OF_LETTERS;
       }
       input[i] = ch;
   }else if(ch >='0' && ch<= '9' ){
       ch = ch + CAESAR_SHIFT;
       if(ch>'9'){
           ch = ch - NUMBER_OF_DIGITS;
       }
       input[i] = ch;
   }
   
}
        return input;
}   
char * decryptCaesar(char * input){
for (int i = 0; input[i] != '\0'; i++)
{
   
   char ch = input[i];
   if(ch >='a' && ch<= 'z' ){
       ch = ch - CAESAR_SHIFT;
       if(ch<'a'){
           ch = ch + NUMBER_OF_LETTERS;
       }
       input[i] = ch;
   }else if(ch >='A' && ch<= 'Z' ){
       ch = ch - CAESAR_SHIFT;
       if(ch<'A'){
           ch = ch + NUMBER_OF_LETTERS;
       }
       input[i] = ch;
   }else if(ch >='0' && ch<= '9' ){
       ch = ch - CAESAR_SHIFT;
       if(ch<'0'){
           ch = ch + NUMBER_OF_DIGITS;
       }
       input[i] = ch;
   }
   
}
return input;
}
