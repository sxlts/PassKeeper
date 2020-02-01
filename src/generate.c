#include "generate.h"

char* generate(int size){
    char* password;
    password = malloc (size);

    srand(time(NULL)); 

    for(int i = 0 ; i < size ; i++){
           password[i] = 33 + rand() % 94; 
    }
    return password;
}
