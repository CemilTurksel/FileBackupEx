#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input,*output;
    char source[50],target[50],character;
    printf("Please enter the name of the file to backup:\n");
    gets(source);
    input=fopen(source,"r");
    if(input==NULL){
        perror("Could not find the file!");
        exit(1);
    }
    else{
        printf("Please enter the location and the name of the file to backup:\n");
        gets(target);
        output=fopen(target,"w");
        if(output==NULL){
            perror("The file could not be created!");
            exit(1);
        }
        else{
            for(character=getc(input);character!=EOF;character=getc(input)){
                putc(character,output);
            }
            fclose(input);
            fclose(output);
            printf("Backup process is done successfully!");
        }
    }
    return 0;
}
