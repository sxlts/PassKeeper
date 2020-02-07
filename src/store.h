#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int SAVE(char* FilePath , char* FileName , char* Pass , char* EncryptionKey);

char** READ(char* FilePath , char* EncryptionKey);
