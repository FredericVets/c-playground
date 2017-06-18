#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "fibonnaci.h"

static void displayDataTypeLimits() {
	// Constants defined in limits.h

	printf("(signed) char minimum (CHAR_MIN) : %hhi\n", CHAR_MIN);
	printf("(signed) char maximum (CHAR_MAX) : %hhi\n", CHAR_MAX);
	printf("unsigned char maximum (UCHAR_MAX) : %hhu\n\n", UCHAR_MAX);

	printf("(signed) short minimum (SHRT_MIN) : %hi\n", SHRT_MIN);
	printf("(signed) short maximum (SHRT_MAX) : %hi\n", SHRT_MAX);
	printf("unsigned short maximum (USHRT_MAX) : %hu\n\n", USHRT_MAX);

	printf("(signed) integer minimum (INT_MIN) : %i\n", INT_MIN);
	printf("(signed) integer maximum (INT_MAX) : %i\n", INT_MAX);
	printf("unsigned integer maximum (UINT_MAX) : %u\n\n", UINT_MAX);

	printf("(signed) long minimum (LONG_MIN) : %li\n", LONG_MIN);
	printf("(signed) long maximum (LONG_MAX) : %li\n", LONG_MAX);
	printf("unsigned long maximum (ULONG_MAX) : %lu\n\n", ULONG_MAX);
}

static int isStringNumerical(char *c) {
	while (*c) {
		if (!isdigit(*c))
			return 0; // false

		c++;
	}

	return 1; // true
}

int main(int argc, char** argv){
	if (argc != 2) {
		puts("You need to specify an index!");
		return 1;
	}

	if (!isStringNumerical(argv[1])){
		puts("Index needs to be numerical!");
		return 1;
	}

	int index = (int)(strtol(argv[1], NULL, 10));
	if (index < 0) {
		puts("Index needs to be a positive integer!");
		return 1;
	}

	displayDataTypeLimits();

	printFibonnaci(index);

	return 0;
}