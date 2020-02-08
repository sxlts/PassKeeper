#include "unittest.h"
#include "store.h"
#include "generate.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void reverse(char *x, int begin, int end)
{
   char c;

   if (begin >= end)
      return;

   c          = *(x+begin);
   *(x+begin) = *(x+end);
   *(x+end)   = c;

   reverse(x, ++begin, --end);
}

char* my_itoa(int n){
	int Counter = 1;
	char* Out = malloc(1);
	while(n){
		Out[Counter - 1] = n%10 + 48;
		n/=10;
		Counter++;
		Out = (char*) realloc(Out, Counter * sizeof(char));
	}
	Out[Counter - 1] = '\0';
	reverse(Out, 0 , Counter - 2);

	return Out;
}

int main() {
	int solenj = 0;
	
	int KeySize = 256;
	int PassSize = 256;
	int TestCounts = 1000;

	char* temp = generate(KeySize);
	char* Key = malloc(strlen(temp));
	strcpy(Key , temp);

	char** PassArr;
	PassArr = malloc(TestCounts * sizeof(char*));

	for (int i = 0 ; i < TestCounts ; i++){
		PassArr[i] = malloc(strlen(my_itoa(i + 1)) + PassSize + 2);
	}	
	for (int i = 0 ; i < TestCounts ; i++){
		strcat(PassArr[i], my_itoa(i + 1));
		strcat(PassArr[i], ":");

		temp = generate(PassSize);
		strcat(PassArr[i], temp);

		PassArr[i][strlen(my_itoa(i + 1)) + PassSize + 1] = '\0';

		SAVE("test.bin", my_itoa(i + 1), temp, Key);
	}
	
	char** FileData = READ("test.bin", Key);
	if(FileData == NULL){
		printf("I/O Error!\n");
		exit(1);
	}

	for(int i = 0 ; i < TestCounts ; i++){
		unit_test(!strcmp(PassArr[i] , FileData[i]), "checking storing integrity");
	}
	
	report();

	return 0;
}
