#include "encrypt.h"

char* encrypt(char* pass , char* key){
	unsigned long SizeKey = strlen(key);
	unsigned long SizePass = strlen(pass);
	
	char* EncryptedKey;
	EncryptedKey = malloc (SizePass);
	strcpy(EncryptedKey , pass);

	for(int i = 0 ; i < SizePass; i ++){
		EncryptedKey[i] = (short)EncryptedKey[i] ^ (short)key[i%SizeKey];
	}
	return EncryptedKey;
}
