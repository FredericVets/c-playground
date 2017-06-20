#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* to_upper(char *string);           // Does not modify the input.
void convert_to_upper(char *string);    // Modifies the input.

char* encrypt(char *string);
void convert_to_encrypted(char *string);

char *decrypt(char *string);
void convert_to_decrypted(char *string);

char *longest(char *left, char *right);

// Test those functions.
int main() {
    char string[] = "Some input string!";

    convert_to_upper(string);
    printf("convert_to_upper : %s\n", string);

    convert_to_encrypted(string);
    printf("convert_to_encrypted : %s\n", string);

    convert_to_decrypted(string);
    printf("convert_to_decrypted : %s\n", string);


    char *bla_ptr = "blaaa";
    char *encrypted_bla_ptr = encrypt(bla_ptr);
    printf("original bla value : %s\n", bla_ptr);
    printf("encrypted bla value : %s\n", encrypted_bla_ptr);

    char *left = "In a galaxy ...";
    char *right = "Far far away ...";
    printf("The longest string : %s\n", longest(left, right));

    return 0;
}

// Does not modify input.
char* to_upper(char *string) {
    char *temp;
    strcpy(temp, string);

    convert_to_upper(temp);

    return temp;
}

// Modifies input.
void convert_to_upper(char *string) {
    while (*string) {
        *string = toupper(*string);

        string++;
    }
}

char* encrypt(char *string) {
    char *temp;
    strcpy(temp, string);

    convert_to_encrypted(temp);

    return temp;
}

void convert_to_encrypted(char *string) {
    while (*string) {
        *string = *string + 1;

        string++;
    }
}

char *decrypt(char *string) {
    char *temp;
    strcpy(temp, string);

    convert_to_decrypted(temp);

    return temp;
}

void convert_to_decrypted(char *string) {
    while (*string) {
        *string = *string - 1;

        string++;
    }
}

char *longest(char *left, char *right) {
    return strlen(left) >= strlen(right) ? left : right;
}
