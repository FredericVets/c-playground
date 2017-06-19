#include <stdio.h>
#include <ctype.h>

void arrays_in_disguise() {
    // Arrays are pointers in disguise.
    char name[] = "John Doe";
    char *ptr = "John Doe";

    printf("sizeof name : %lu\n", sizeof(name));
    printf("sizeof ptr : %lu\n", sizeof(ptr));
    printf("Name : %s\n", ptr);

    while (*ptr) {
        putchar(*ptr);
        putchar('\n');

        ptr++;
    }
}

void convert_to_upper(char *string) {
    // In both cases, the character '\0' (null byte) will cause the loop to exit.
    // The pointer way;
    while (*string) {
        *string = toupper(*string);
        string++;
    }

    return;

    // The array way;
    for (int i = 0; string[i]; i++)
        string[i] = toupper(string[i]);
}

int main() {
    arrays_in_disguise();

    char string[] = "shouting!";
    char c = 'c';

    convert_to_upper(string);
    convert_to_upper(&c);

    char *char_p = &c;
    printf("address 1 : %p\n", char_p);
    printf("address 2 : %p\n", char_p[1]);
    printf("value 1 : %c\n", char_p[0]);
    printf("value 2 : %i\n", char_p[1]);

    printf("convert_to_upper result : %s\n", string);
    printf("convert_to_upper result : %c\n", c);

    return 0;
}

