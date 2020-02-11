#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "sodium.h"

#define FIRST_SYMBOL 33
#define ALPHABET_SIZE 94


bool is_strong(char* password);

char* generate(int size);

