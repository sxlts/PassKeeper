#include "generate.h"
#include "encrypt.h"
#include "store.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void PrintHelp(){
       printf("Usage:\n		generate [size] [name]\n	ecrypt\n	exit\n");
}

int main(int argc, char **argv){
        char *LookUp[3] = {"help" , "generate" , "exit"};
        if(argc == 1){
		PrintHelp();
		return 0;
        }
        if(strcmp(argv[1],"generate") == 0){
		int size = 8;
		if(argc > 2) size = atoi(argv[2]);
                printf("password is: %s\n",generate(size > 8 ? size : 8));
        }
	if(strcmp(argv[1],"encrypt") == 0){
		char *temp;

	        temp = getpass("give password:\n");
		char *Pass;
		Pass = malloc(strlen(temp));
		strcpy(Pass , temp);

		temp = getpass("give key:\n");
		char *Key;
		Key = malloc(strlen(temp));
		strcpy(Key , temp);

		printf("[DEBUG]: %s , %s \n" , Pass , Key);

		printf("encrypted pass is:\n");
		for(int i = 0 ; i < strlen(Pass) ; i ++){
			printf("%c" , *(encrypt(Pass,Key) + i));
		}
		printf("\n");

	}
	if(strcmp(argv[1],"save") == 0){
		char* FilePath;
		char* PassName = malloc(50);
		char* Pass;
		char* EncryptionKey;
		if(argc > 2){
			FilePath = malloc(strlen(argv[2]));
			strcpy(FilePath , argv[2]);

			printf("Give Password Name\n");
			scanf("%s" , PassName);

			char* temp;

			temp = getpass("give password:\n");
			Pass = malloc(strlen(temp));
			strcpy(Pass , temp);
	
			temp = getpass("give key:\n");
			EncryptionKey = malloc(strlen(temp));
			strcpy(EncryptionKey , temp);

			printf("[DEBUG]: %s , %s , %s , %s\n" , FilePath , PassName , Pass , EncryptionKey);

			if(SAVE(FilePath , PassName , Pass , EncryptionKey) == 0){
				printf("Success!\n");
			}
			else{
				printf("error!\n");
			}
		}
		else{
			PrintHelp();
		}

	}
        return 0;
}
