#include "generate.h"
#include "encrypt.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
        char *LookUp[3] = {"help" , "generate" , "exit"};
        if(argc == 1){
                printf("Usage:\n	generate [size] [name]\n	exit\n");
                return 0;
        }
        if(strcmp(argv[1],"generate") == 0){
                printf("generate...\n");
		int size = 8;
		if(argc > 2) size = atoi(argv[2]);
                printf("password is: %s\n",generate(size > 8 ? size : 8));
        }
	if(strcmp(argv[1],"encrypt") == 0){
		char *temp = getpass("Give password:\n");

		char *Pass = malloc(strlen(temp));
	       	strcpy(Pass , temp);

		temp = getpass("Give key:\n");

		char *Key = malloc(strlen(temp));
	       	strcpy(Key , temp);
		
		printf("Pass : %s , Key : %s\n" , Pass , Key);
		printf("encrypted pass is:\n");
		
		for(int i = 0 ; i < strlen(Pass) ; i ++){
			printf("%c" , *(encrypt(Pass,Key) + i));
		}
		printf("\ncheck :\n");
		for(int i = 0 ; i < strlen(Pass) ; i ++){
			printf("%c" , *(encrypt(encrypt(Pass , Key) , Key) + i));
		}
		printf("\n");
	}
        printf("finished!\n");
        return 0;
}
