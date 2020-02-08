#include "unittest.h"

#include "store.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static char* KEY = "SOMEKEY_123";
static char* TEST_NAME = "TEST";
static char* FILE_PATH = "test.psk";

static char** TEST_CASE = NULL;
static char** FILE_OUT = NULL;
static int TEST_SIZE = 5;
static int PASS_SIZE = 50;

void put(char* Pass){	
	SAVE(FILE_PATH, TEST_NAME, Pass, KEY);
}

bool check(char* Pass){
	int i = 0;
	char* line = NULL;
	line = malloc(strlen(TEST_NAME) + strlen(Pass) + 2);

	strcpy(line, "");
	strcat(line, TEST_NAME);
	strcat(line, ":");
	strcat(line, Pass);
	
	for(int i = 0 ; i < TEST_SIZE ; i++){
		if(strcmp(FILE_OUT[i], line) == 0) return true;
	}
	return false;
}

int main() {
	TEST_CASE = malloc(TEST_SIZE * sizeof(char*));
	for(int i = 0 ; i < TEST_SIZE ; i++){
		TEST_CASE[i] = malloc(PASS_SIZE * sizeof(char));
	}
	
	remove(FILE_PATH);

	strcpy(TEST_CASE[0] , "vndknGuhRT6%^&GHV");
	strcpy(TEST_CASE[1] , "123abcABC!@#");
	strcpy(TEST_CASE[2] , "RDT6%^&GHV");
	strcpy(TEST_CASE[3] , "RD7395783549HV");
	strcpy(TEST_CASE[4] , "12345678");
	
	for(int i = 0 ; i < TEST_SIZE ; i++){
		put(TEST_CASE[i]);
	}

	FILE_OUT = READ(FILE_PATH, KEY);
	remove(FILE_PATH);

	for(int i = TEST_SIZE - 1 ; i>= 0 ; i--){
		unit_test(check(TEST_CASE[i]), ("%s saved", TEST_CASE[i]));
	}

	return report();
}
