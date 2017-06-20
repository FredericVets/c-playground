#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void itterate_as_pointer(char *string) {
    // while (*string) is a shorthand for : while (*string != '\0'), the null-byte.
    while (*string) {
        putchar(*string);
        string++;
    }

    putchar('\n');
}

static void itterate_as_array(char *string) {
    for (int i=0; string[i]; i++)
        putchar(string[i]);

    putchar('\n');
}

static void convert_to_upper(char *string) {
    while (*string) {
        *string = toupper(*string);
        string++;
    }
}

int main() {
    /*
    A string literal (the formal term for a double-quoted string in C source) can be used in two slightly different ways:

    1. As the initializer for an array of char, as in the declaration of char a[] , it specifies the initial values of
        the characters in that array (and, if necessary, its size).
        Stored on the stack. So MODIFIABLE!
    2. Anywhere else, it turns into an unnamed, static array of characters, and this unnamed array may be stored in
        read-only memory, and which therefore cannot necessarily be modified. In an expression context, the array is
        converted at once to a pointer, as usual (see section 6), so the second declaration initializes p to point to
        the unnamed array's first element.
        Stored in the rodata segment. So NOT MODIFIABLE!

    See : https://stackoverflow.com/questions/1335786/c-differences-between-char-pointer-and-array
    Great and interesting comments are mentioned in it.
    */

    // Case 1.
    char array_string[] = "This string is assigned to an array.";
    // Case 2.
    char *pointer_string = "This string is assigned to a pointer.";

    /*
    arrays like array_string are NOT pointers.
    Array objects do not store an address anywhere (which should be clear from the memory map).
    Rather, array expressions will "decay" to pointer types unless they are operands of the unary & or sizeof operators
    (hence the difference in behavior for sizeof)

    see https://stackoverflow.com/questions/4607128/in-c-are-arrays-pointers-or-used-as-pointers/4608421#4608421
    */

    printf("Address of array_string = %p\n", array_string);
    printf("strlen(array_string) = %lu\n", strlen(array_string));
    printf("sizeof array_string = %lu\n\n", sizeof array_string); // IMPORTANT !

    printf("Address of pointer_string = %p\n", pointer_string);
    printf("strlen(pointer_string) = %lu\n", strlen(pointer_string));
    printf("sizeof pointer_string = %lu\n\n", sizeof pointer_string);

    itterate_as_pointer(array_string);
    itterate_as_array(array_string);

    itterate_as_pointer(pointer_string);
    itterate_as_array(pointer_string);

    convert_to_upper(array_string);
    printf("array_string in uppercase : %s\n", array_string);

    // This will cause an ERROR because read-only memory is attempted to be written to.
//    convert_to_upper(pointer_string);
//    printf("array_string in uppercase : %s\n", pointer_string);

    return 0;
}
