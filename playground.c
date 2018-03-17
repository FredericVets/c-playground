#include <stdio.h>
#include <string.h>
#include <time.h>

int global;

static void pointers() {
	int var = 42;
	int var2;
	int *intp = NULL;

	intp = &var;
	var++;

	printf("Address of variable var : %p\n", &var);
	printf("Address of variable intp: %p\n", &intp);
	printf("Address stored in variable intp: %p\n", intp);

	// Dereference the intp pointer.
	printf("Value of dereferenced variable *intp : %d\n", *intp);
	printf("Value of uninitialized var2 : %d\n", var2);
	printf("Value of global : %d\n", global);
}

static int sum_by_value(int array[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += array[i];

	return sum;
}

static int sum_by_reference(int *array, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += array[i];

	return sum;
}

static void arrays() {
	int myArray[4] = {10, 20, 30, 40};
	int result_by_value = sum_by_value(myArray, 4);
	int result_by_reference = sum_by_reference(myArray, 4);

	printf("sum : %d\n", result_by_value);
	printf("sum : %d\n", result_by_reference);

	int *myArray_p[4];
	for (int i = 0; i < 4; i++) {
		myArray_p[i] = &myArray[i];
	}

	for (int i = 0; i < 4; i++) {
		printf("value of myArray_p[%d] = %d\n", i, *myArray_p[i]);
	}
}

struct person {
	char name[12];
	int age;
};

void structs() {
	struct person frederic = { "Frederic", 33 };

	printf("Person.name = %s\n", frederic.name);
	printf("Person.name length = %lu\n", strlen(frederic.name));
	printf("Person.age = %d\n", frederic.age);

	struct person *frederic_p = &frederic;
	printf("Person.name = %s\n", frederic_p->name);
	printf("Person.name length = %lu\n", strlen(frederic_p->name));
	printf("Person.age = %d\n", (*frederic_p).age);

	struct person john;
	strcpy(john.name, "John");
	john.age = 60;
}

static void timeTest() {
    // Usage of time();
    time_t now;
    long now_ticks = time(&now);
    printf("Seconds since Unix Epoch : %lu\n", now_ticks);
    printf("Seconds since Unix Epoch : %lu\n", now);

    printf("The current time is : %s\n", ctime(&now));

    // Usage of localtime();
    struct tm *local_now;
    local_now = localtime(&now);

    printf(
        "Today is %d/%02d at %d:%02d:%02d\n",
        local_now->tm_mday,
        local_now->tm_mon + 1, // Months start at 0
        local_now->tm_hour,
        local_now->tm_min,
        local_now->tm_sec);
}

int main(int argc, char **argv) {
	pointers();
	arrays();
	structs();
	timeTest();

	printf("'%d' arguments are passed.\n", argc);

	for(int i=0; i < argc; i++)
		printf("Argument %d : %s\n", i, argv[i]);

	return 0;
}
