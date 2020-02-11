#include "generate.h"


bool is_strong(char* password){
  bool HasUpper = 0, HasLower = 0, HasDigit = 0, HasSpec = 0;
  for(int i = 0 ; i < strlen(password) ; i++){
    if(isupper(password[i]))	HasUpper = 1;
      else
    if(islower(password[i]))	HasLower = 1;
      else
    if(isdigit(password[i]))	HasDigit = 1;
      else
    HasSpec = 1;
  }
  return (HasSpec && HasDigit && HasLower && HasUpper);
}

char* generate(int size){

	if (sodium_init() < 0) {
        	printf("panic! the library couldn't be initialized, it is not safe to use");
    	}

	char* password;
	password = malloc (size + 1);
	password[size] = '\0';

	srand(time(NULL));

	while(!is_strong(password)){
		for(int i = 0 ; i < size ; i++){
			password[i] = FIRST_SYMBOL + randombytes_uniform(ALPHABET_SIZE);
		}
	}

	return password;
}
