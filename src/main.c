#include "generate.h"
#include "encrypt.h"
#include "store.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void PrintHelp(){
       printf("Usage:\n	generate [size] [name]\n	ecrypt\n	exit\n");
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
	if(strcmp(argv[1],"save") == 0){
		char* FilePath = "";
		char* PassName = malloc(50);
		char* Pass = "";
		char* EncryptionKey = "";
		if(argc > 2){
			FilePath = malloc(strlen(argv[2]));
			strcpy(FilePath , argv[2]);

			printf("Give Password Name\n");
			scanf("%s" , PassName);

			char* temp;
			while(strlen(Pass) == 0){
	        		temp = getpass("give password:\n");
				Pass = malloc(strlen(temp));
				strcpy(Pass , temp);
			}
			while(strlen(EncryptionKey) == 0){
				temp = getpass("give key:\n");
				EncryptionKey = malloc(strlen(temp));
				strcpy(EncryptionKey , temp);
			}

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
			return 0;
		}

	}
	if(strcmp(argv[1],"read") == 0){
		char* FilePath = "";
		char* EncryptionKey = "";
		if(argc > 2){
			FilePath = malloc(strlen(argv[2]));
			strcpy(FilePath , argv[2]);

			char* temp;
			while(strlen(EncryptionKey) == 0){
				temp = getpass("give key:\n");
				EncryptionKey = malloc(strlen(temp));
				strcpy(EncryptionKey , temp);
			}

			if(READ(FilePath , EncryptionKey) == 0){
				printf("success!\n");
			}
			else{
				printf("error!\n");
			}
		}
		else{
			PrintHelp();
			return 0;
		}
	}
        return 0;
}
