#include "store.h"

int SAVE(char* FilePath, char* PassName, char* Pass, char* EncryptionKey){
	FILE *file;

	file = fopen(FilePath, "ab+");
	if(file == NULL){
		return 1;
	}
	
	unsigned int PassLength = strlen(Pass);
	
	//write length of string for reading
	fwrite(&PassLength, sizeof(unsigned int), 1, file);
	
	//write passname
	fwrite(PassName, sizeof(char), strlen(PassName), file);
	
	//write parser
	char parser = ':';
	fwrite(&parser, sizeof(char), 1, file);

	for(int i = 0 ; i < strlen(Pass) ; i++){
		char byte = Pass[i] ^ EncryptionKey[i % strlen(EncryptionKey)];
		fwrite(&byte, sizeof(char), 1, file);
	}

	return 0;
}

int READ(char* FilePath, char* EncryptionKey){
	FILE *file;

	file = fopen(FilePath, "rb");
	if(file == NULL){
		return 1;
	}
	unsigned int StringLength;

	printf("\n");

	while(fread(&StringLength, sizeof(int), 1, file)){
		char* line = malloc(StringLength);	
		
		char byte = '0';

		while(byte != ':'){
			fread(&byte, sizeof(char), 1, file);
			printf("%c", byte);
		}
		for(int i = 0 ; i < StringLength ; i++){
			fread(&byte, sizeof(char), 1, file);
			byte = byte ^ EncryptionKey[i % strlen(EncryptionKey)];
			printf("%c", byte);
		}
		printf("\n");
	}

	printf("\n");

	fclose(file);

	return 0;
}

