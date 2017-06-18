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

void printFibonnaci(int index);