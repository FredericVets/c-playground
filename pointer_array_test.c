#include <stdio.h>

static void pointer_array();
static void two_dimensional_array();

int main() {
    pointer_array();
    two_dimensional_array();

    return 0;
}

static void pointer_array() {
    char *persons[3] = {
        "John Doe",
        "Jane Doe",
        "Foo Bar"
    };

    char *person_ptr;
    for (int i=0; i < 3; i++) {
        person_ptr = *(persons + i);

        printf("Address of person %u = %p\n", i, person_ptr);
        printf("Person %u = %s\n", i, person_ptr);
    }
}

static void two_dimensional_array() {
    char data[3][11] = {
        "0123456789",
        "abcde",
        "fghij"
    };

    // Using pointer syntax;
    char *item_ptr;
    for (int i=0; i < 3; i++) {
        item_ptr = *(data + i);

        printf("data %u = %s\n", i, item_ptr);
    }

    // Using array syntax;
    for (int i = 0; i < 3; i++)
        printf("data %u = %s\n", i, data[i]);
}
