#include <stdlib.h>
#include <string.h>

#include "unittest.h"
#include "generate.h"

char WeakPass[50][50] = {
	"abcdefgh",
	"12345678",
	"abcd1234",
	"abCD1234",
	"abcdABCD",
	"ab!@ABCD",
	"!@#$1236",
	""
};

char StrongPass[50][50] = {
	"ABC^Solenji228",
	"1234!@#$abAB",
	""
};

char* STRSUM(char* a, char* b){
	char* temp = malloc(strlen(a) + strlen(b));
	strcpy(temp, a);
	strcat(temp, b);
	return temp;
}

int main() {
	int i = 0;
	while(strlen(WeakPass[i]) != 0){
		unit_test(!is_strong(WeakPass[i]), STRSUM(WeakPass[i], " is weak password"));
		i++;
	}
	i = 0;
	while(strlen(StrongPass[i]) != 0){
		unit_test(is_strong(StrongPass[i]), STRSUM(StrongPass[i], " is strong password"));
		i++;
	}

	unit_test(is_strong(generate(8)), "generate() create strong password");
	return report();
}
