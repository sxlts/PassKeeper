#include "store.h"

int SAVE(char* FilePath , char* PassName , char* Pass , char* EncryptionKey){
	FILE *file;

	file = fopen(FilePath , "wb");
	if(file == NULL){
		return 1;
	}
	
	unsigned int PassLength = strlen(PassName) + strlen(Pass) + 1;
	
	//write length of string for reading
	fwrite(&PassLength , sizeof(int) , 1 , file);	
	
	//write passname
	fwrite(PassName , sizeof(char) , strlen(PassName) , file);
	
	//write parser
	char parser = ':';
	fwrite(&parser , sizeof(char) , 1 , file);

	//write encrypted pass
	char* temp = encrypt(Pass , EncryptionKey);
	for(int i = 0 ; i < strlen(Pass) ; i++){
		char byte = temp[i];
		fwrite(&byte , sizeof(char) , 1 , file);
	}

	return 0;
}

int READ(char* FilePath , char* EncryptionKey){
	FILE *file;

	file = fopen(FilePath , "rb");
	if(file == NULL){
		return 1;
	}

	unsigned int StringLength;
       	fread(&StringLength , sizeof(int) , 1 , file);
	
	char* line = malloc(StringLength);
	fread(line , sizeof(char) , StringLength , file);	

	fclose(file);

	char key = 0;
	unsigned int KeyCounter = 0;

	for(int i = 0 ; i < strlen(line) ; i++){
		if(!key)
			printf("%c" , line[i]);
		else{
			printf("%c" , line[i]^EncryptionKey[KeyCounter%strlen(EncryptionKey)]);
			KeyCounter++;
		}

		if(line[i] == ':') {
			key = 1;
		}
	}

	return 0;
}

