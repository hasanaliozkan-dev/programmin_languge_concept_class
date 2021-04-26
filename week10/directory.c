#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main(){
    FILE *fileptr = fopen("deneme.txt","w");
    struct dirent *de;
    DIR *dir= opendir(".");
    if (dir ==NULL)
    {
        printf("We couldnt open this directory\n");
        return 0;
    }
    while ((de = readdir(dir))!=NULL)
    {
        printf("\t%s\n",de->d_name);
    }
    if(remove("deneme.txt") ==0){
        printf("removed succesfully\n");
    }
    fclose(fileptr);
    closedir(dir);
    return 0;
}