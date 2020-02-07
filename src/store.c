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

	return 0;
}

char** READ(char* FilePath, char* EncryptionKey){
	FILE *file;

	file = fopen(FilePath, "rb");
	if(file == NULL){
		return NULL;
	}
	unsigned int StringLength;

	char** Output;
	int OutCounter = 0;

	while(fread(&StringLength, sizeof(int), 1, file)){
		printf("[DEBUG] strLen = %d" , StringLength);

		char* line = malloc(StringLength);	
		
		OutCounter++;
		Output = (char**) realloc (Output , OutCounter *  sizeof(char*));
		Output[OutCounter - 1] = malloc (StringLength + 1);

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

		printf("[DEBUG] %s\n" , Output[OutCounter - 1]);
	}
	fclose(file);

	return Output;
}

