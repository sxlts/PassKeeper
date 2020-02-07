#include "store.h"

int SAVE(char* FilePath, char* PassName, char* Pass, char* EncryptionKey){
	FILE *file;

	file = fopen(FilePath, "ab+");
	if(file == NULL){
		return 1;
	}
	
	unsigned int PassLength = strlen(PassName) + strlen(Pass) + 1;

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
	
	fclose(file);
	return 0;
}

char** READ(char* FilePath, char* EncryptionKey){
	FILE *file;

	file = fopen(FilePath, "rb");
	if(file == NULL){
		return NULL;
		printf("I/O error!\n");
	}
	unsigned int StringLength;

	char** Output = NULL;
	int OutCounter = 0;
	
	while(fread(&StringLength, sizeof(unsigned int), 1, file)){
		char* line = malloc(StringLength);	
		
		OutCounter++;
		Output = realloc (Output , 2 * OutCounter * sizeof(char*));
		
		Output[OutCounter - 1] = malloc(StringLength + 1);

		char byte = '0';
		int counter = 0;

		while(byte != ':'){
			fread(&byte, sizeof(char), 1, file);
			Output[OutCounter - 1][counter] = byte;
			counter++;	
		}

		StringLength-= counter;

		for(int i = 0 ; i < StringLength ; i++){
			fread(&byte, sizeof(char), 1, file);
			byte = byte ^ EncryptionKey[i % strlen(EncryptionKey)];
			Output[OutCounter - 1][counter] = byte;
			counter++;
		}
		
		Output[OutCounter - 1][counter] = '\0';
	}
	fclose(file);

	return Output;
}

