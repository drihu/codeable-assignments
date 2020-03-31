#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

bool isNumeric(string text);

int main(int argc, string argv[]) {
    if (argc == 1 || argc > 2 || atoi(argv[1]) == 0 || !isNumeric(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string p = get_string("plaintext: ");
    int length = strlen(p);
    int c;

    printf("ciphertext: ");
    for (int i = 0; i < length; i++) {
        if (p[i] > 64 && p[i] < 91) {
            c = (p[i] - 64 + key) % 26 + 64;
        } else if (p[i] > 96 && p[i] < 123) {
            c = (p[i] - 96 + key) % 26 + 96;
        } else {
            c = p[i];
        }
        printf("%c", c);
    }
    printf("\n");
}

bool isNumeric(string text) {
    for (int i = 0, len = strlen(text); i < len; i++) {
        if (text[i] < 48 || text[i] > 57) {
            return false;
        }
    }
    return true;
}
