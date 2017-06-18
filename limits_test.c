#include <stdio.h>
#include <limits.h>

static void displayDataTypeLimits() {
	// Constants defined in limits.h
	// (see https://en.wikipedia.org/wiki/C_data_types)

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

int main() {
	displayDataTypeLimits();

	return 0;
}