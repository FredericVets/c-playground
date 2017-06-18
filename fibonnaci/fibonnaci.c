#include <stdio.h>
#include <stdlib.h>
#include "fibonnaci.h"

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
static DATA_TYPE fibonnaci(int index, DATA_TYPE cache[]) {
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
void printFibonnaci(int index) {
	// Setup the cache.
	DATA_TYPE cache[index + 1];
	initializeCache(index + 1, cache);
	
	for (int i=0; i <= index; i++)
		printf("fibonnaci(%d) = %" PRINTF_FORMAT_SPECIFIER "\n", 
			i, 
			fibonnaci(i, cache));
}