#include "generate.h"

char* generate(int size){
	char* password;
	password = malloc (size);

	srand(time(NULL));

	char strong = 0;

	while(!strong){
		for(int i = 0 ; i < size ; i++){
			password[i] = 33 + rand() % 94;
		}

		char HasNum = 0 , HasUpper = 0 , HasLower = 0 , HasSpec = 0;

		for(int i = 0 ; i < size ; i++){
			if(64 < password[i] && password[i] < 91)	HasUpper = 1;
			else
			if(96 < password[i] && password[i] < 123)	HasLower = 1;
			else
			if(47 < password[i] && password[i] < 58)	HasNum = 1;
			else
				HasSpec = 1;
		}

		if(HasSpec && HasNum && HasLower && HasUpper) strong = 1;
	}

	return password;
}
