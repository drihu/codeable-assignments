#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

bool isNumeric(string text);
char * cipher(string text, int key);

int main(int argc, string argv[]) {
    if (argc == 1 || argc > 2 || !isNumeric(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("plaintext: ");
    int key = atoi(argv[1]);

    printf("ciphertext: ");
    printf("%s\n", cipher(text, key));
}

char * cipher(string text, int key) {
    int len = strlen(text);
    static char c[255];

    for (int i = 0; i < len; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            c[i] = (text[i] - 64 + key) % 26 + 64;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            c[i] = (text[i] - 96 + key) % 26 + 96;
        } else {
            c[i] = text[i];
        }
    }

    return c;
}

bool isNumeric(string text) {
    for (int i = 0, len = strlen(text); i < len; i++) {
        if (text[i] < '0' || text[i] > '9') return false;
    }
    return true;
}
