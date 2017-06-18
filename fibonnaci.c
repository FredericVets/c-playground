#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#define UNINITIALIZED 0
#define DATA_TYPE unsigned long
#define MAX_VALUE ULONG_MAX
#define PRINTF_FORMAT_SPECIFIER "lu"

/*
	Format Specifiers :
	(see https://en.wikipedia.org/wiki/C_data_types)

	(signed) short		:	hi
	unsigned short		:	hu
	(signed) int		:	d or i
	unsigned int		:	u
	(signed) long		:	li
	unsigned long		:	lu
	unsigned long long	:	llu
*/

void displayDataTypeLimits() {
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

static void initializeCache(int count, DATA_TYPE cache[]) {
	for (int i=0; i < count; i++)
		cache[i] = UNINITIALIZED;
}

static void addToCache(int index, DATA_TYPE value, DATA_TYPE cache[]) {
	if (cache[index] != UNINITIALIZED)
		return;

	cache[index] = value;
}

static int doesAdditionOverflow(DATA_TYPE left, DATA_TYPE right) {
	return left > (MAX_VALUE - right);
}

/*
 0, 1, 1, 2, 3, 5, 8, 13, 21
 Every number after the first two is the sum of the two preceding ones.
 Index parameter is zero based.
*/
DATA_TYPE fibonnaci(int index, DATA_TYPE cache[]) {
        if (index == 0) {
		addToCache(0, 0, cache);
		return 0;
	}
        if (index == 1) {
		addToCache(1, 1, cache);
		return 1;
	}

	if (cache[index] != UNINITIALIZED)
		return cache[index];

	DATA_TYPE left = fibonnaci(index - 2, cache);
	DATA_TYPE right = fibonnaci(index - 1, cache);
	if (doesAdditionOverflow(left, right)) {
		puts("error : Overflow detected!");
		exit(1);
	}

	DATA_TYPE fibo = left + right;
	addToCache(index, fibo, cache);

	return fibo;
}

// Index parameter is zero based.
void printFibonnaci(int index, DATA_TYPE cache[]) {
        for (int i=0; i <= index; i++)
                printf("fibonnaci(%d) = %" PRINTF_FORMAT_SPECIFIER "\n", i, fibonnaci(i, cache));
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

	// Setup the cache.
	DATA_TYPE cache[index + 1];
	initializeCache(index + 1, cache);

	printFibonnaci(index, cache);

	return 0;
}
