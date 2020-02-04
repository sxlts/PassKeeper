#include "generate.h"

char* generate(int size){

	if (sodium_init() < 0) {
        	printf("panic! the library couldn't be initialized, it is not safe to use");
    	}

	char* password;
	password = malloc (size);

	srand(time(NULL));

	char strong = 0;

	while(!strong){
		for(int i = 0 ; i < size ; i++){
			password[i] = FIRST_SYMBOL + randombytes_uniform(ALPHABET_SIZE);
		}

		char HasDigit = 0 , HasUpper = 0 , HasLower = 0 , HasSpec = 0;

		for(int i = 0 ; i < size ; i++){
			if(isupper(password[i]))	HasUpper = 1;
				else
			if(islower(password[i]))	HasLower = 1;
				else
			if(isdigit(password[i]))	HasDigit = 1;
				else
							HasSpec = 1;
		}

		if(HasSpec && HasDigit && HasLower && HasUpper) strong = 1;
	}

	return password;
}
