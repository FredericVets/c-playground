#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fibonnaci.h"

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

	printFibonnaci(index);

	return 0;
}